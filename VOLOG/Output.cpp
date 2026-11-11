#include "Output.hpp"
#include <iostream>

void PrintMenu()
{
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
}

void PrintAssorrtiment(std::string goods[], int cost[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << ". " << goods[i] << ". Цена: " << cost[i] << "\n";
	}
}

void PrintTotalDiscount(double totalDiscount)
{
	std::cout << "Ваша скидка: " << totalDiscount << "\n";
}

void PrintCheck(double check)
{
	std::cout << "Итоговая стоимость: " << check << "\n";
}