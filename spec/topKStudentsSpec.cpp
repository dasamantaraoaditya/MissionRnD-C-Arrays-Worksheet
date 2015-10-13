#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/topKStudents.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(topKStudentsSpec)
	{
	public:

		TEST_METHOD(negativeKValue)
		{
			struct student students[3] = { { "stud1", 70 }, { "stud2", 60 }, { "stud3", 50 } };
			struct student **result = topKStudents(students, 3, -3);
			bool isValid = false;
			if (result == NULL) {
				isValid = true;
			}
			Assert::AreEqual(true, isValid, L"Negative K value case failed.", LINE_INFO());
		}

		TEST_METHOD(zeroKValue)
		{
			struct student students[3] = { { "stud1", 70 }, { "stud2", 60 }, { "stud3", 50 } };
			struct student **result = topKStudents(students, 3, 0);
			bool isValid = false;
			if (result == NULL) {
				isValid = true;
			}
			Assert::AreEqual(true, isValid, L"K value zero case failed.", LINE_INFO());
		}

		TEST_METHOD(KGreaterThanLength)
		{
			struct student students[3] = { { "stud1", 50 }, { "stud2", 60 }, { "stud3", 70 } };
			struct student **result = topKStudents(students, 3, 5);
			Assert::AreEqual(50, result[0]->score, L"K greater than length case failed.", LINE_INFO());
			Assert::AreEqual(60, result[1]->score, L"K greater than length case failed.", LINE_INFO());
			Assert::AreEqual(70, result[2]->score, L"K greater than length case failed.", LINE_INFO());
		}

		TEST_METHOD(KValue1)
		{
			struct student students[3] = { { "stud1", 50 }, { "stud2", 60 }, { "stud3", 70 } };
			struct student **result = topKStudents(students, 3, 1);
			Assert::AreEqual(50, result[0]->score, L"K value 1 case failed.", LINE_INFO());
		}

		TEST_METHOD(positiveKValue)
		{
			struct student students[3] = { { "stud1", 50 }, { "stud2", 60 }, { "stud3", 70 } };
			struct student **result = topKStudents(students, 3, 2);
			Assert::AreEqual(50, result[0]->score, L"K value 2 case failed.", LINE_INFO());
			Assert::AreEqual(60, result[1]->score, L"K value 2 case failed.", LINE_INFO());
			struct student students1[3] = { { "stud1", 50 }, { "stud2", 60 }, { "stud3", 70 } };
			struct student **result1 = topKStudents(students1, 3, 3);
			Assert::AreEqual(50, result1[0]->score, L"K value 3 case failed.", LINE_INFO());
			Assert::AreEqual(60, result1[1]->score, L"K value 3 case failed.", LINE_INFO());
			Assert::AreEqual(70, result1[2]->score, L"K value 3 case failed.", LINE_INFO());
		}

	};
}