#ifndef STORE_H
#define STORE_H

#include <string>
#include <iostream>


void PrintAssorrtiment(std::string goods[], int cost[], int size);

double CalculateCostGoods(std::string goods[], int costGoods[], int size, double& totalDiscount);

int ChoiceGoods(std::string goods[], int size);

int ChoiceNumberOfGoods();

bool IsDiscountTea(std::string goods[], int choice, int numberOfGoods);

bool IsFreeJuice(std::string goods[], int choice, int numberOfGoods);

double CalculateDiscount(double priceGoods, double sale);

double CalculateDiscount(int costGoods[], int choice, int numberOfGoods);

void PrintTotalCount(double check, double totalDiscount, double sale);

bool IsExitFromCategory();

#endif