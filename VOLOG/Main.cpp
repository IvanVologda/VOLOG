#include <iostream>
# include <windows.h>

void PrintAssorrtiment(std::string goods[], int cost[], int size);
int CalculateCostCategory(std::string goods[], int costGoods[]);

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	const int numberOfFruitJuice = 4;
	const int numberOfVegetablesJuice = 3;
	const int numberOfTea = 2;
	int choice = 0;
	double check = 0.0, salePercent = 13, sale = 0;

	std::string fruitJuice[numberOfFruitJuice]
	{ "Яблочный сок", "Апельсиновый сок", "Абрикосовый сок", "Грушевый сок" };
	std::string vegetablesJuice[numberOfVegetablesJuice]
	{ "Томатный сок", "Луковый сок", "Огуречный сок" };
	std::string tea[numberOfTea]
	{ "Чесночный чай", "Петрушевый чай" };

	int costFruitJuice[numberOfFruitJuice]{ 150, 160, 200 , 210 };
	int costVegetablesJuice[numberOfVegetablesJuice]{ 120, 60, 130 };
	int costTea[numberOfTea]{ 300, 400 };


	while (true)
	{
		system("cls");
		std::cout << "\t\tМАГАЗИН \"СОКИ АЛЕКАНДРА\"\n\n";
		std::cout << "\tПродажа соков и чая в литровых банках\n\n";
		std::cout << "Ассортимент магазина по категориям: \n\n";
		std::cout << "1. Фруктовые соки.\n";
		std::cout << "2. Овощные соки.\n";
		std::cout << "3. Чай.\n";
		std::cout << "4. Рассчитать итоговую стоимость.\n";
		std::cout << "0. выход из магазина.\n";
		std::cout << "\n\n\n\n\t\t\t\tИтоговая сумма:" << check;
		std::cout << "\n\nВыберите категорию: ";
		std::cin >> choice;

		if (choice > 4 || choice < 0) 
		{
			std::cout << "Ошибка. Повторите ввод.";
			system("pause");
			system("cls");
		}

		if (choice == 1)
		{
			system("cls");
			std::cout << "\tФруктовые соки\n";
			PrintAssorrtiment(fruitJuice, costFruitJuice, numberOfFruitJuice);
			
			check += CalculateCostCategory(fruitJuice, costFruitJuice);
		}
		else if (choice == 2)
		{
			system("cls");
			std::cout << "\tОвощные соки\n";
			PrintAssorrtiment(vegetablesJuice, costVegetablesJuice, numberOfVegetablesJuice);

			check += CalculateCostCategory(vegetablesJuice, costVegetablesJuice);
		}
		else if (choice == 3)
		{
			system("cls");
			std::cout << "\tЧаи\n";
			PrintAssorrtiment(tea, costTea, numberOfTea);
			check += CalculateCostCategory(tea, costTea);
		}
		else if (choice == 4)
		{
			if (check > 1500)
			{
				sale = check * (salePercent / 100);
				check -= sale;
			}
			system("cls");

			std::cout << "\n\n\n\n\t\t\tИтоговая сумма: " << check;
			std::cout << "\n\n\n\n\t\t\tВаша скидка: " << sale;

			system("pause");
			system("cls");
			break;
		}
		else if (choice == 0)
		{
			break;
		}
	}
}

void PrintAssorrtiment(std::string goods[], int cost[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << ". " << goods[i] << ". Цена: " << cost[i] << "\n";
	}
}

int CalculateCostCategory(std::string goods[], int costGoods[])
{
	int choice = 0, numberOfGoods = 0, priceCategory = 0, freeGoods = 0;
	double saleTea = 5;

	std::cout << "Если хотите выбрать другую, категорию нажмите 0.";
	std::cout << "Выберите товар: ";
	std::cin >> choice;

	if (choice == 0)
	{
		return 0;
	}
	else
	{
		std::cout << "Введите количество товаров: ";
		std::cin >> numberOfGoods;

		while (numberOfGoods < 0)
		{
			std::cout << "Товара не может быть меньше нуля!\n";
			std::cout << "Введите количество товаров: ";
			std::cin >> numberOfGoods;
		}
		
		if (goods[choice - 1] == "Петрушевый чай" && numberOfGoods >= 3)
		{
			priceCategory = costGoods[choice - 1] * numberOfGoods * ((100 - saleTea) / 100.0);
			std::cout << "Ваша скидка на чай: " << costGoods[choice - 1] * numberOfGoods * (saleTea / 100.0) << "\n";
			system("pause");
			return priceCategory;
		}

		if (goods[choice - 1] == "Луковый сок") 
		{
			freeGoods = numberOfGoods / 4;
			priceCategory = costGoods[choice - 1] * (numberOfGoods - freeGoods);
			std::cout << freeGoods << " литра бесплатно!\n";
			system("pause");
			return priceCategory;
		}

		priceCategory = costGoods[choice - 1] * numberOfGoods;
		return priceCategory;
	}
}


