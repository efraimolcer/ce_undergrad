//////////////////////////
// Name: Efraim Olcer   //
// SID:  150190713	    //
// Mail: olcer16		//
//////////////////////////

#include <stdio.h>
#include <stdlib.h>		// abs, RAND_MAX
#include <stdbool.h>

#define SIZE 50			// Maximum value of park size

/*
 * @func	Get park size for the square park area from the user
 * @return	size: Park size
 * @param	-
 */
int get_park_size(){
	int size;
	
	printf("Size: ");
	scanf("%d", &size);
	
	while(size > 50 || size < 1){
		printf("Size must be between 50 and 1\n");
		printf("Size: ");
		scanf("%d", &size);
	}
	
	return size;
}

/*
 * @func	Get number of cars in the park area from the user
 * @return	car_num: Number of cars
 * @param	size: Park size
 */
int get_car_num(int size){
	int car_num;
	
	printf("Cars: ");
	scanf("%d", &car_num);
	
	while(car_num > size * size || car_num < 0){
		printf("Number of cars must be between %d and 0\n", size * size);
		printf("Cars: ");
		scanf("%d", &car_num);
	}
	
	// If number of cars equals to the size of the park area, flag it as full
	if (car_num == size * size)
		return RAND_MAX;			// RAND_MAX is used as a full-flag
	else
		return car_num;
}

/*
 * @func	Get each car's location in X and Y axis
 * @return	-
 * @param	park[][]: park area map, 0: empty, 1: full
 * 			car_num: Number of cars
 * 			size: Park size
 */
void get_car_loc(int park[][SIZE], int car_num, int size){
	int x, y;
	
	for (int i = 0; i < car_num; i++){
		printf("Locations: ");
		scanf("%d %d", &x, &y);		// Location starts from 1
		
		// If location values are smaller than 1 or bigger than the size, skip given values
		if (x > size || y > size || x < 1 || y < 1)
			continue;
		
		park[x - 1][y - 1] = 1;
	}
}

/*
 * @func	Initialize given square array cells with given value
 * @return	-
 * @param	arr[][]: Uninitialized array
 * 			size: Size limit of the array both for columns and rows
 * 			value: Value that is used to initialize the array
 */
void initialize_arr(int arr[][SIZE], int size, int value){
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] = value;
}

/*
 * @func	Find the minimum distance using Manhattan Distance for each parking place
 * @return	-
 * @param	park[][]: park area map, 0: empty, 1: full
 * 			distance[][]: minimum distance values for each parking place
 * 			size: Park size
 */
void find_distance(int park[][SIZE], int distance[][SIZE], int size){
	for (int i = 0; i < size; i++){										// Search for all parking places, i: row, j: column
		for (int j = 0; j < size; j++){
			if (park[i][j] == 0){										//	Find empty parking place
				for (int x = 0; x < size; x++){							// 		Measure distance between the empty place and all full parking places
					for (int y = 0; y < size; y++){
						if (park[x][y] == 1 &&							//		If the place is full and
							abs(i - x) + abs(j - y) < distance[i][j])	//		If the measurement is smaller than the current distance value
							distance[i][j] = abs(i - x) + abs(j - y);	//			Store the new measurement as minimum distance for the empty place
					}
				}
			}
			else														//	If it is not found an empty place, it is full and measurement is 0.
				distance[i][j] = 0;
		}
	}
}

/*
 * @func	Find the best slot which has the largest minimum distance
 * @return	-
 * @param	distance[][]: minimum distance values for each parking place
 * 			size: Park size
 */
void find_best_slot(int distance[][SIZE], int size){
	int max		= distance[0][0],
		max_i	= 0,
		max_j	= 0;
	
	for (int i = 0; i  < size; i++){
		for(int j = 0; j < size; j++){
			if ((distance[i][j] > max) ||									// If the distance value for the slot is bigger than local maximum
				(distance[i][j] == max && i == max_i && j < max_j) || 		// Or if the distance & x values of the distance is equal to the local maximum's & y value is smaller than the local maximum's y value
				(distance[i][j] == max && i < max_i)) {						// Or if the distance is equal to the local maximum's and  x value is smaller than the local maximum's x value
				// Update the maximum value
				max = distance[i][j];
				max_i = i;
				max_j = j;
			}
		}
	
	printf("Best Slot Found In: %d %d\n", max_i + 1, max_j + 1);
}

int main(){
	// Get the size of the parking area
	int size;
	size = get_park_size();
	
	// Initialize arrays
	int park[SIZE][SIZE];
	int distance[SIZE][SIZE];
	
	initialize_arr(park, size, 0);
	initialize_arr(distance, size, RAND_MAX);
	
	// Get the number of cars parked in the area
	int car_num;
	car_num = get_car_num(size);
	
	if (car_num != RAND_MAX){
		// Get each car's location in X and Y axis
		get_car_loc(park, car_num, size);
		// Find minimum distances
		find_distance(park, distance, size);
		// Find the largest minimum distance slot
		find_best_slot(distance, size);
	}
	else
		printf("Best Slot Found In: %d %d\n", 0, 0);
		
	return 0;
}

/*	CALICO
	python3 -m calico.cli assignment3.t
	init ..................................... PASSED
	build .................................... PASSED
	case0 .................................... PASSED
	case1 .................................... PASSED
	case2 .................................... PASSED
	case3 .................................... PASSED
	case4 .................................... PASSED
	case5 .................................... PASSED
	Grade: 100 / 100
*/