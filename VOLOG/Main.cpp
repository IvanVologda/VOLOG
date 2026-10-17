#include <iostream>
#include <windows.h>
#include <string>

void PrintAssorrtiment(std::string goods[], int cost[], int size);

double CalculateCostGoods(std::string goods[], int costGoods[], int size, double &totalDiscount);

int ChoiceGoods(std::string goods[], int size);

int ChoiceNumberOfGoods();

bool IsDiscountTea(std::string goods[], int choice, int numberOfGoods);

bool IsFreeJuice(std::string goods[], int choice, int numberOfGoods);

double CalculateDiscount(double priceGoods, double sale);

double CalculateDiscount(int costGoods[], int choice, int numberOfGoods);

void PrintTotalCount(double check, double totalDiscount, double sale);

bool IsExitFromCategory();

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

double CalculateCostGoods(std::string goods[], int costGoods[], int size, double &totalDiscount)
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