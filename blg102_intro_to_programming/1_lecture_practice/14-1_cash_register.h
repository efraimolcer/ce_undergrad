#ifndef CASH_REGISTER_H
	#define CASH_REGISTER_H
	
	class cash_register{
		public:
			cash_register();
			cash_register(int, double);
			void	clear();
			void	add_price(double);
			double	get_total_amount()		const;
			int		get_item_count()		const;
		
		private:
			double	total_amount;
			int		item_count;
	
	};
#endif