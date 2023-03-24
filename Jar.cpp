#include "Jar.h"

bool Jar::pour(Jar* jar_dest)
{
	if (!Current_amount)
		return false;
	if (jar_dest->getAmount() == jar_dest->getCapacity())
		return false;

	int pour_sum = Current_amount + jar_dest->getAmount();

	if (pour_sum  <= jar_dest->getCapacity())
	{
		jar_dest->setAmount(pour_sum);
		Current_amount = 0;
	}
	else
	{
		jar_dest->setAmount(jar_dest->getCapacity());
		Current_amount = pour_sum - jar_dest->getCapacity();
	}

	return true;
	

}

void Jar::setAmount(int amount)
{
	Current_amount = amount;
}
int Jar::getAmount()
{
	return Current_amount;
}

int Jar::getCapacity()
{
	return capacity;
}