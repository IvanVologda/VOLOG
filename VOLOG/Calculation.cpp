#include "Calculation.hpp"

bool IsDiscountTea(std::string goods[], int choice, int numberOfGoods)
{
	return goods[choice - 1] == "Петрушевый чай" && numberOfGoods >= 3;
}

bool IsFreeJuice(std::string goods[], int choice)
{
	return goods[choice - 1] == "Луковый сок";
}

double CalculateDiscountTea(double  priceGoods, double sale)
{
	return priceGoods * sale;
}

int GetNumberOfFreeLitres(int numberOfGoods)
{
	int freeJuice = numberOfGoods / 4;

	return freeJuice;
}

double GetValueFreeLiters(int freeLitres, int costGoods[], int choice)
{
	return freeLitres * costGoods[choice - 1];
}

double CalculateCostGoods(std::string goods[], int costGoods[], double& totalDiscount, int choice, int numberOfGoods)
{
	double priceGoods = costGoods[choice - 1] * numberOfGoods;
	double saleTea = 0.05;
	double discount = 0;

	if (IsDiscountTea(goods, choice, numberOfGoods))
	{
		discount = CalculateDiscountTea(priceGoods, saleTea);
		totalDiscount += discount;
		return priceGoods - discount;
	}

	if (IsFreeJuice(goods, choice))
	{
		discount = GetValueFreeLiters(GetNumberOfFreeLitres(numberOfGoods), costGoods, choice);
		totalDiscount += discount;
		return priceGoods - discount;
	}

	return priceGoods;
}	

double GetGlobalDiscount(double check, double totalDiscount, double sale, const double limitForSale)
{
	if (check > limitForSale)
	{
		return totalDiscount + check * sale;
	}

	return totalDiscount;
}

double GetCheck(double check, double sale, const double limitForSale)
{
	if (check > limitForSale)
	{
		return check - (check * sale);
	}

	return check;
}