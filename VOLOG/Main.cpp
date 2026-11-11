#include "Calculation.hpp"
#include "input.hpp"
#include "Output.hpp"
#include <windows.h>
#include <iostream>

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	const double limitForSale = 3000;

	const int numberOfFruitJuice = 4;
	const int numberOfVegetablesJuice = 3;
	const int numberOfTea = 2;
	const int numberOfTinctures = 1;

	std::string fruitJuice[numberOfFruitJuice]
	{ "Яблочный сок", "Апельсиновый сок", "Абрикосовый сок", "Грушевый сок" };
	std::string vegetablesJuice[numberOfVegetablesJuice]
	{ "Томатный сок", "Луковый сок", "Огуречный сок" };
	std::string tea[numberOfTea]
	{ "Чесночный чай", "Петрушевый чай" };
	std::string tinctures[numberOfTinctures]
	{ "Настойка из боярышника" };

	bool canBuyHawtron = true;
	bool isBuyHawtron = false;
	double costHawtron = 0;

	double priceGoods = 0.0;
	double check = 0.0;
	double sale = 0.13;
	double totalDiscount = 0.0;
	int itemNumber = 0;
	int numberOfGoods = 0;

	int costFruitJuice[numberOfFruitJuice]{ 150, 160, 200 , 210 };
	int costVegetablesJuice[numberOfVegetablesJuice]{ 120, 60, 130 };
	int costTea[numberOfTea]{ 300, 400 };
	int costTinctures[numberOfTinctures]{ 500 };

	int choice = 0;

	while (true)
	{
		system("cls");
		PrintMenu();

		std::cin >> choice;

		switch (choice)
		{
		case 1:

			PrintAssorrtiment(fruitJuice, costFruitJuice, numberOfFruitJuice);

			if (IsExitFromCategory())
			{
				break;
			}

			itemNumber = ChoiceGoods(fruitJuice, numberOfFruitJuice);
			numberOfGoods = ChoiceNumberOfGoods();

			priceGoods = CalculateCostGoods(fruitJuice, costFruitJuice, totalDiscount, itemNumber, numberOfGoods);
			check += priceGoods;

			if (isBuyHawtron)
			{
				std::cout << "Вы купили фруктовый сок, поэтому покупка настойки из боярышника будет аннулирована!\n";
				check -= costHawtron;
				costHawtron = 0;
				isBuyHawtron = false;
			}

			canBuyHawtron = false;
			break;

		case 2:

			PrintAssorrtiment(vegetablesJuice, costVegetablesJuice, numberOfVegetablesJuice);

			if (IsExitFromCategory())
			{
				break;
			}

			itemNumber = ChoiceGoods(vegetablesJuice, numberOfVegetablesJuice);
			numberOfGoods = ChoiceNumberOfGoods();

			priceGoods = CalculateCostGoods(vegetablesJuice, costVegetablesJuice, totalDiscount, itemNumber, numberOfGoods);
			check += priceGoods;
			break;

		case 3:

			PrintAssorrtiment(tea, costTea, numberOfTea);

			if (IsExitFromCategory())
			{
				break;
			}

			itemNumber = ChoiceGoods(tea, numberOfTea);
			numberOfGoods = ChoiceNumberOfGoods();

			priceGoods = CalculateCostGoods(tea, costTea, totalDiscount, itemNumber, numberOfGoods);
			check += priceGoods;
			break;

		case 4:

			if (canBuyHawtron == false)
			{
				std::cout << "Вы не можете купить настойку из боярышника, так как вы купили фруктовый сок!\n";
				break;
			}

			PrintAssorrtiment(tinctures, costTinctures, numberOfTinctures);

			if (IsExitFromCategory())
			{
				break;
			}

			itemNumber = ChoiceGoods(tinctures, numberOfTinctures);
			numberOfGoods = ChoiceNumberOfGoods();

			priceGoods = CalculateCostGoods(tinctures, costTinctures, totalDiscount, itemNumber, numberOfGoods);
			costHawtron += priceGoods;
			check += priceGoods;
			isBuyHawtron = true;
			break;

		case 5:
		{
			double finalDiscount = GetGlobalDiscount(check, totalDiscount, sale, limitForSale);
			double finalCheck = GetCheck(check, sale, limitForSale);

			if (finalDiscount > 0)
				PrintTotalDiscount(finalDiscount);

			PrintCheck(finalCheck);
			break;
		}

		case 0:

			std::cout << "Спасибо за покупку!\n";
			return 0;

		default:

			std::cout << "Выберите категорию из ассортимента!\n";
			break;
		}

		system("pause");
	}
}