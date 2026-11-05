#include "store.hpp"

void PrintAssorrtiment(std::string goods[], int cost[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << ". " << goods[i] << ". Цена: " << cost[i] << "\n";
	}
}

int ChoiceGoods(std::string goods[], int size)
{
	int choice = 0, numberOfGoods = 0;
	std::cout << "Выберите товар: ";
	std::cin >> choice;

	while (choice < 1 || choice > size)
	{
		std::cout << "Выберите товар из ассортимента: ";
		std::cin >> choice;
	}

	return choice;
}

int ChoiceNumberOfGoods()
{
	int numberOfGoods = 0;
	std::cout << "Введите количество литров: ";
	std::cin >> numberOfGoods;

	while (numberOfGoods < 1)
	{
		std::cout << "Количество должно быть не меньше 1!\n";
		std::cout << "Введите количество литров: ";
		std::cin >> numberOfGoods;
	}
	return numberOfGoods;
}

double CalculateCostGoods(std::string goods[], int costGoods[], int size, double& totalDiscount)
{
	double priceGoods = 0;
	double sale = 0.05;
	int choice = ChoiceGoods(goods, size);
	int numberOfGoods = ChoiceNumberOfGoods();
	double discount = 0;

	priceGoods = costGoods[choice - 1] * numberOfGoods;

	if (IsDiscountTea(goods, choice, numberOfGoods))
	{
		discount = CalculateDiscount(priceGoods, sale);
		totalDiscount += discount;
		return priceGoods - discount;
	}

	if (IsFreeJuice(goods, choice, numberOfGoods))
	{
		discount = CalculateDiscount(costGoods, choice, numberOfGoods);
		totalDiscount += discount;
		return priceGoods - discount;
	}

	return priceGoods;
}

bool IsDiscountTea(std::string goods[], int choice, int numberOfGoods)
{
	if (goods[choice - 1] == "Петрушевый чай" && numberOfGoods >= 3)
	{
		return true;
	}

	return false;
}

bool IsFreeJuice(std::string goods[], int choice, int numberOfGoods)
{
	if (goods[choice - 1] == "Луковый сок")
	{
		return true;
	}

	return false;
}

double CalculateDiscount(double  priceGoods, double sale)
{
	std::cout << "Ваша скидка: " << priceGoods * sale << "\n";

	return priceGoods * sale;
}

double CalculateDiscount(int costGoods[], int choice, int numberOfGoods)
{
	int freeJuice = numberOfGoods / 4;
	std::cout << freeJuice << " литра бесплатно!\n";

	return freeJuice * costGoods[choice - 1];
}

bool IsExitFromCategory()
{
	int choice = 0;
	std::cout << "Если хотите выбрать другую категорию нажмите 0. Если остаетесь введите любое другое число\n";
	std::cin >> choice;

	if (choice == 0)
	{
		return true;
	}

	return false;
}

void PrintTotalCount(double check, double totalDiscount, double sale)
{

	if (check > 3000)
	{
		std::cout << "Ваша скидка: " << totalDiscount + (check * sale) << "\n";
		check -= check * sale;
	}
	else if (totalDiscount > 0)
	{
		std::cout << "Ваша скидка: " << totalDiscount << "\n";
	}

	std::cout << "Итоговая стоимость: " << check << "\n";
}