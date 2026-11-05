#include <iostream>
#include <windows.h>
#include <string>
#include "store.hpp"

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	const double limitForSale = 3000;
	
	const int numberOfFruitJuice = 4;
	const int numberOfVegetablesJuice = 3;
	const int numberOfTea = 2;
	const int numberOfTinctures = 1;

	bool canBuyHawtron = true;
	bool isBuyHawtron = false;
	int costHawtron = 0;
	double priceGoods = 0.0;
	double check = 0.0;
	double sale = 0.13;
	double totalDiscount = 0.0;

	std::string fruitJuice[numberOfFruitJuice]
	{ "Яблочный сок", "Апельсиновый сок", "Абрикосовый сок", "Грушевый сок" };
	std::string vegetablesJuice[numberOfVegetablesJuice]
	{ "Томатный сок", "Луковый сок", "Огуречный сок" };
	std::string tea[numberOfTea]
	{ "Чесночный чай", "Петрушевый чай" };
	std::string tinctures[numberOfTinctures]
	{ "Настойка из боярышника" };

	int costFruitJuice[numberOfFruitJuice]{ 150, 160, 200 , 210 };
	int costVegetablesJuice[numberOfVegetablesJuice]{ 120, 60, 130 };
	int costTea[numberOfTea]{ 300, 400 };
	int costTinctures[numberOfTinctures]{ 500 };

	int choice = 0;

	while (true)
	{
		system("cls");
		std::cout << "\t\tМАГАЗИН \"СОКИ АЛЕКАНДРА\"\n\n";
		std::cout << "\tПродажа соков и чая в литровых банках\n\n";
		std::cout << "Ассортимент магазина по категориям: \n\n";
		std::cout << "1. Фруктовые соки.\n";
		std::cout << "2. Овощные соки.\n";
		std::cout << "3. Чай.\n";
		std::cout << "4. Настойки.\n";
		std::cout << "5. Рассчитать итоговую стоимость.\n";
		std::cout << "0. выход из магазина.\n";

		std::cout << "\n\nВыберите категорию: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:

			PrintAssorrtiment(fruitJuice, costFruitJuice, numberOfFruitJuice);

			if (IsExitFromCategory())
			{
				break;
			}

			priceGoods = CalculateCostGoods(fruitJuice, costFruitJuice, numberOfFruitJuice, totalDiscount);
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

			priceGoods = CalculateCostGoods(vegetablesJuice, costVegetablesJuice, numberOfVegetablesJuice, totalDiscount);
			check += priceGoods;
			break;

		case 3:

			PrintAssorrtiment(tea, costTea, numberOfTea);

			if (IsExitFromCategory())
			{
				break;
			}

			priceGoods = CalculateCostGoods(tea, costTea, numberOfTea, totalDiscount);
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

			priceGoods = CalculateCostGoods(tinctures, costTinctures, numberOfTinctures, totalDiscount);
			costHawtron += priceGoods;
			check += priceGoods;
			isBuyHawtron = true;
			break;

		case 5:

			PrintTotalCount(check, totalDiscount, sale);
			break;
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