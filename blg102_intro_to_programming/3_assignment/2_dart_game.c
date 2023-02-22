//////////////////////////
// Name: Efraim Olcer   //
// SID:  150190713	    //
// Mail: olcer16		//
//////////////////////////

#include <stdio.h>

/*
 * @func	Calculate the throw value
 * @return	The point value for the throw.
 * @param	segment: Landing a dart in a segment scores the number value for that segment.
 * 			ring: Changing the multiplicity or the exact value of the segment based on it. (S:Single, D: Double, T: Triple, I: Inner, O: Outer)
 */
int throw_value(int segment, char ring){
	int value;

	if (ring == 'S')
		value = segment;
	else if (ring == 'D')
		value = segment * 2;
	else if (ring == 'T')
		value = segment * 3;
	else if (ring == 'O')
		value = 25;
	else if (ring == 'I')
		value = 50;
	else
		value = 0;
	
	return value;
}

/*
 * @func	Calculate the throw value
 * @return	The point value for the throw.
 * @param	curr_point: Remaining score before the current throw.
 * 			target: Given value by the user, the player has to reach a target number of points.
 * 			segment: Landing a dart in a segment scores the number value for that segment.
 * 			ring: Changing the multiplicity or the exact value of the segment based on it. (S:Single, D: Double, T: Triple, I: Inner, O: Outer)
 */
int game_point(int curr_point, int target, int segment, char ring){
	int updated_point = curr_point,
		value;
	
	// Calculate the throw value
	value = throw_value(segment, ring);

	// Check for the last throw
	if (curr_point - value == 0 && ring == 'D')						// Player has to reach the exact point value 0, and again with a throw in the double ring.
		updated_point = 0;
	// Update the current point only in two conditions
	else if ((curr_point == target && ring == 'D') ||				// To start scoring, the player has to land a dart in the double ring.
			(curr_point != target && (curr_point - value > 1)))		// If the needed value is exceeded or the remaining point value is 1, the points don’t get counted.
		updated_point -= value;
	// If both conditions are not satisfied, current point should not be changed.

	return updated_point;
}

int main(){
	// Get the target
	int		target;
	printf("Target: ");
	scanf("%d", &target);
	printf("\n");
	
	// Run the game
	int		segment,
			point = target;
	char	ring;
	while (point != 0){
		// Get the throw
		printf("Throw: ");
		scanf("%d %c", &segment, &ring);

		// Calculate the game point & Print the current point
		point = game_point(point, target, segment, ring);
		printf("Points: %d\n", point);
	}
	
	return 0;
}

/*	CALICO
	python3 -m calico.cli assignment2.t
	init ..................................... PASSED
	build .................................... PASSED
	case0 .................................... 5 / 5
	case1 .................................... 5 / 5
	case2 .................................... 5 / 5
	case3 .................................... 5 / 5
	case4 .................................... 5 / 5
	case5 .................................... 5 / 5
	case6 .................................... 4 / 4
	case7 .................................... 6 / 6
	case8 .................................... 6 / 6
	case9 .................................... 6 / 6
	case10 ................................... 6 / 6
	case11 ................................... 6 / 6
	case12 ................................... 6 / 6
	case13 ................................... 6 / 6
	case14 ................................... 6 / 6
	case15 ................................... 6 / 6
	case16 ................................... 6 / 6
	case17 ................................... 6 / 6
	Grade: 100 / 100
*/