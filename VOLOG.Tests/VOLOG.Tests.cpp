#include "pch.h"
#include "CppUnitTest.h"
#include "../VOLOG/Calculation.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VOLOGTests
{
	TEST_CLASS(VOLOGTests)
	{
	public:

		const double kTolerance = 0.01;

		TEST_METHOD(GetNumberOfFreeLitres_4Litres_Returns_1)
		{
			// Arrange

			int expected = 1;
			int litres = 4;
				
			// Act

			int actual = GetNumberOfFreeLitres(litres);

			// Assert

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetNumberOfFreeLitres_3Litres_Returns_0)
		{
			// Arrange

			int expected = 0;
			int litres = 3;

			// Act
			int actual = GetNumberOfFreeLitres(litres);

			// Assert

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetNumberOfFreeLitres_8Litres_Returns_2)
		{
			// Arrange

			int expected = 2;
			int litres = 8;

			// Act

			int actual = GetNumberOfFreeLitres(litres);

			// Assert

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetNumberOfFreeLitres_7Litres_Returns_1)
		{
			// Arrange

			int expected = 1;
			int litres = 7;

			// Act

			int actual = GetNumberOfFreeLitres(litres);

			// Assert

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CalculateDiscountTea_1200Rubles_005Sale_Returns_60)
		{
			// Arrange

			double expected = 60.0;
			double rubles = 1200.0;
			double discount = 0.05;

			// Act

			double actual = CalculateDiscountTea(rubles, discount);

			// Assert

			Assert::AreEqual(expected, actual, kTolerance);
		}
		TEST_METHOD(CalculateDiscountTea_0Rubles_005Sale_Returns_0)
		{
			// Arrange

			double expected = 0.0;
			double rubles = 0.0;
			double discount = 0.05;
			double tolerance = 0.01;

			// Act

			double actual = CalculateDiscountTea(rubles, discount);

			// Assert

			Assert::AreEqual(expected, actual, tolerance);
		}

		TEST_METHOD(IsDiscountTea_ParsleyTeaChoice_3NumberOfTea_ReturnsTrue)
		{
			// Arrange

			std::string tea[2]{ "Чесночный чай", "Петрушевый чай" };
			int choice = 2;
			int numberOfTea = 3;

			// Act

			bool isDiscount = IsDiscountTea(tea, choice, numberOfTea);

			// Assert

			Assert::IsTrue(isDiscount);
		}

		TEST_METHOD(IsDiscountTea_ParsleyTeaChoice_2NumberOfTea_ReturnsFalse)
		{
			// Arrange

			std::string tea[2]{ "Чесночный чай", "Петрушевый чай" };
			int choice = 2;
			int numberOfTea = 2;

			// Act

			bool isDiscount = IsDiscountTea(tea, choice, numberOfTea);

			// Assert

			Assert::IsFalse(isDiscount);
		}

		TEST_METHOD(IsDiscountTea_GarlicTeaChoice_4NumberOfTea_ReturnsFalse)
		{
			// Arrange

			std::string tea[2]{ "Чесночный чай", "Петрушевый чай" };
			int choice = 1;
			int numberOfTea = 4;

			// Act

			bool isDiscount = IsDiscountTea(tea, choice, numberOfTea);

			// Assert

			Assert::IsFalse(isDiscount);
		}

		TEST_METHOD(IsFreeJuice_OnionJuiceChoice_ReturnsTrue)
		{
			// Arrange

			std::string vegetablesJuice[3]{ "Томатный сок", "Луковый сок", "Огуречный сок" };
			int choice = 2;

			// Act

			bool isFreeJuice = IsFreeJuice(vegetablesJuice, choice);

			// Assert

			Assert::IsTrue(isFreeJuice);
		}

		TEST_METHOD(IsFreeJuice_CucumberJuiceChoice_ReturnsFalse)
		{
			// Arrange

			std::string vegetablesJuice[3]{ "Томатный сок", "Луковый сок", "Огуречный сок" };
			int choice = 3;

			// Act

			bool isFreeJuice = IsFreeJuice(vegetablesJuice, choice);

			// Assert

			Assert::IsFalse(isFreeJuice);
		}

		TEST_METHOD(GetValueFreeLiters_2FreeLiters_Returns_120)
		{
			// Arrange

			int costVegetablesJuice[3]{ 120, 60, 130 };
			int choice = 2;
			int freeLitres = 2;
			double expected = 120.0;

			// Act

			double actual = GetValueFreeLiters(freeLitres,costVegetablesJuice, choice);

			// Assert

			Assert::AreEqual(expected, actual, 0.01);
		}

		TEST_METHOD(GetValueFreeLiters_0FreeLiters_Returns_0)
		{
			// Arrange

			int costVegetablesJuice[3]{ 120, 60, 130 };
			int choice = 2;
			int freeLitres = 0;
			double expected = 0.0;

			// Act

			double actual = GetValueFreeLiters(freeLitres,costVegetablesJuice, choice);

			// Assert

			Assert::AreEqual(expected, actual, kTolerance);
		}

		TEST_METHOD(CalculateCostGoods_BuyParsleyTea_Returns1520_TotalDiscount80)
		{
			// Arrange

			std::string tea[2]{ "Чесночный чай", "Петрушевый чай" };
			int costTea[2]{ 300, 400 };
			int choice = 2;
			int numberOfGoods = 4;
			double totalDiscount = 0.0;
			double expectedTotalDiscount = 80.0;
			double expectedPrice = 1520.0;

			// Act

			double actualPrice = CalculateCostGoods(tea, costTea, totalDiscount, choice, numberOfGoods);

			// Assert

			Assert::AreEqual(expectedPrice, actualPrice, kTolerance);
			Assert::AreEqual(expectedTotalDiscount, totalDiscount, kTolerance);
		}

		TEST_METHOD(CalculateCostGoods_BuyOnionJuice_Returns360_TotalDiscount120)
		{
			// Arrange

			std::string vegetablesJuice[3]{ "Томатный сок", "Луковый сок", "Огуречный сок" };
			int costVegetablesJuice[3]{ 120, 60, 130 };
			int choice = 2;
			int numberOfGoods = 8;
			double totalDiscount = 0.0;
			double expectedTotalDiscount = 120.0;
			double expectedPrice = 360.0;

			// Act

			double actualPrice = CalculateCostGoods(vegetablesJuice, costVegetablesJuice, totalDiscount, choice, numberOfGoods);

			// Assert

			Assert::AreEqual(expectedPrice, actualPrice, kTolerance);
			Assert::AreEqual(expectedTotalDiscount, totalDiscount, kTolerance);
		}

		TEST_METHOD(CalculateCostGoods_BuyAppleJuice_Returns1050_TotalDiscount0)
		{
			// Arrange

			std::string fruitJuice[4]{ "Яблочный сок", "Апельсиновый сок", "Абрикосовый сок", "Грушевый сок" };
			int costFruitJuice[4]{ 150, 160, 200 , 210 };
			int choice = 1;
			int numberOfGoods = 7;
			double totalDiscount = 0.0;
			double expectedTotalDiscount = 0.0;
			double expectedPrice = 1050.0;

			// Act

			double actualPrice = CalculateCostGoods(fruitJuice, costFruitJuice, totalDiscount, choice, numberOfGoods);

			// Assert

			Assert::AreEqual(expectedPrice, actualPrice, kTolerance);
			Assert::AreEqual(expectedTotalDiscount, totalDiscount, kTolerance);
		}

		TEST_METHOD(CalculateCostGoods_BuyOnionJuice_WithExistingDiscount80_Returns240_TotalDiscount140)
		{
			// Arrange

			std::string vegetablesJuice[3]{ "Томатный сок", "Луковый сок", "Огуречный сок" };
			int costVegetablesJuice[3]{ 120, 60, 130 };
			int choice = 2;
			int numberOfGoods = 5;
			double totalDiscount = 80.0;
			double expectedTotalDiscount = 140.0;
			double expectedPrice = 240.0;

			// Act

			double actualPrice = CalculateCostGoods(vegetablesJuice, costVegetablesJuice, totalDiscount, choice, numberOfGoods);

			// Assert

			Assert::AreEqual(expectedPrice, actualPrice, kTolerance);
			Assert::AreEqual(expectedTotalDiscount, totalDiscount, kTolerance);
		}

		TEST_METHOD(GetGlobalDiscount_PurchaseOn3000_Returns340)
		{
			// Arrange

			double check = 3000.0;
			double limitForSale = 3000.0;
			double sale = 0.13;
			double totalDiscount = 340.0;
			double expectedDiscount = 340.0;

			// Act

			double actualDiscount = GetGlobalDiscount(check, totalDiscount, sale, limitForSale);

			// Assert

			Assert::AreEqual(expectedDiscount, actualDiscount, kTolerance);
		}

		TEST_METHOD(GetGlobalDiscount_PurchaseOn3000And1Kopecke_Returns730)
		{
			// Arrange

			double check = 3000.01;
			double limitForSale = 3000.0;
			double sale = 0.13;
			double totalDiscount = 340.0;
			double expectedDiscount = 730.0013;

			// Act

			double actualDiscount = GetGlobalDiscount(check, totalDiscount, sale, limitForSale);

			// Assert

			Assert::AreEqual(expectedDiscount, actualDiscount, kTolerance);
		}

		TEST_METHOD(GetGlobalDiscount_PurchaseOn11200_Returns2476)
		{
			// Arrange

			double check = 11200.0;
			double limitForSale = 3000.0;
			double sale = 0.13;
			double totalDiscount = 1020.0;
			double expectedDiscount = 2476.0;

			// Act

			double actualDiscount = GetGlobalDiscount(check, totalDiscount, sale, limitForSale);

			// Assert

			Assert::AreEqual(expectedDiscount, actualDiscount, kTolerance);
		}

		TEST_METHOD(GetCheck_PurchaseOn3000_Returns3000)
		{
			// Arrange

			double check = 3000.0;
			double limitForSale = 3000.0;
			double sale = 0.13;
			double expectedCheck = 3000.0;

			// Act

			double actualCheck = GetCheck(check, sale, limitForSale);
			// Assert

			Assert::AreEqual(expectedCheck, actualCheck, kTolerance);
		}

		TEST_METHOD(GetCheck_PurchaseOn3000And1Kopecke_Returns2610)
		{
			// Arrange

			double check = 3000.01;
			double limitForSale = 3000.0;
			double sale = 0.13;
			double expectedCheck = 2610.0087;

			// Act

			double actualCheck = GetCheck(check, sale, limitForSale);

			// Assert

			Assert::AreEqual(expectedCheck, actualCheck, kTolerance);
		}

		TEST_METHOD(GetCheck_PurchaseOn11200_Returns9744)
		{
			// Arrange

			double check = 11200.0;
			double limitForSale = 3000.0;
			double sale = 0.13;
			double expectedCheck = 9744.0;

			// Act

			double actualCheck = GetCheck(check, sale, limitForSale);

			// Assert

			Assert::AreEqual(expectedCheck, actualCheck, kTolerance);
		}
	};
}
