#ifndef _CALCULATION_HPP_
#define _CALCULATION_HPP_

#include <string>

bool IsDiscountTea(std::string goods[], int choice, int numberOfGoods);

bool IsFreeJuice(std::string goods[], int choice);

double CalculateDiscountTea(double  priceGoods, double sale);

int GetNumberOfFreeLitres(int numberOfGoods);

double GetValueFreeLiters(int freeLitres, int costGoods[], int choice);

double CalculateCostGoods(std::string goods[], int costGoods[], double& totalDiscount, int choice, int numberOfGoods);

double GetGlobalDiscount(double check, double totalDiscount, double sale, const double limitForSale);

double GetCheck(double check, double sale, const double limitForSale);

#endif // _CALCULATION_HPP_
