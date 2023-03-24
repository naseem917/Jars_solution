#pragma once
class Jar
{
	public:
		Jar(){}
		Jar(int capacity_input, bool filled)
		{
			capacity = capacity_input;
			if(filled)
				Current_amount = capacity_input;
			else
				Current_amount = 0;
		}
		bool pour(Jar* jar_dest);
		void setAmount(int amount);
		int getAmount();
		int getCapacity();



	private:
		int Current_amount;
		int capacity;
};

