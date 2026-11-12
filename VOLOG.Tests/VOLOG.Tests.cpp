#include "pch.h"
#include "CppUnitTest.h"
#include "../VOLOG/Calculation.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VOLOGTests
{
	TEST_CLASS(VOLOGTests)
	{
	public:
		
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
			double tolerance = 0.01;
			// Act
			double actual = CalculateDiscountTea(rubles, discount);
			// Assert
			Assert::AreEqual(expected, actual, tolerance);
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

		TEST_METHOD(IsDiscountTea_2Choice_3NumberOfTea_ReturnsTrue)
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

	};
}
