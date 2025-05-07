#include "pch.h"
#include "CppUnitTest.h"
#include "..\Calc\Calc.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCalc
{
	TEST_CLASS(UnitTestCalc)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			x = 5;
			y = 7;
			calc();
			Assert::AreEqual(12, sum, L"Error El resultado no es el esperado");
		}
	};
}
