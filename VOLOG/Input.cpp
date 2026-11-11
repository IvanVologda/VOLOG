#include "input.hpp"
#include <iostream>

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