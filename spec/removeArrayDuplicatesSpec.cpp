#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/removeArrayDuplicates.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(removeArrayDuplicatesSpec)
	{
	public:

		TEST_METHOD(inValidInputCheck)
		{
			int lessCount, moreCount;
			Assert::IsNull(removeArrayDuplicates(NULL, 1), L"Array NULL check failed.", LINE_INFO());
			int Arr1[1] = { 1 };
			Assert::IsNull(removeArrayDuplicates(Arr1, -2), L"Length less than zero check failed.", LINE_INFO());
		}

		TEST_METHOD(noDuplicates)
		{
			int Arr[3] = { 1, 2, 3 };
			removeArrayDuplicates(Arr, 3);
			Assert::AreEqual(1, Arr[0], L"Value at index 0 should be 1", LINE_INFO());
			Assert::AreEqual(2, Arr[1], L"Value at index 1 should be 2", LINE_INFO());
			Assert::AreEqual(3, Arr[2], L"Value at index 2 should be 3", LINE_INFO());
		}

		TEST_METHOD(unSortedArray)
		{
			int Arr[7] = { 1, 2, 3, 1, 2, 3, 4 };
			removeArrayDuplicates(Arr, 7);
			Assert::AreEqual(1, Arr[0], L"Value at index 0 should be 1", LINE_INFO());
			Assert::AreEqual(2, Arr[1], L"Value at index 1 should be 2", LINE_INFO());
			Assert::AreEqual(3, Arr[2], L"Value at index 2 should be 3", LINE_INFO());
			Assert::AreEqual(4, Arr[3], L"Value at index 3 should be 4", LINE_INFO());
		}

		TEST_METHOD(sortedArray)
		{
			int Arr[6] = { 1, 1, 2, 2, 3, 3 };
			removeArrayDuplicates(Arr, 6);
			Assert::AreEqual(1, Arr[0], L"Value at index 0 should be 1", LINE_INFO());
			Assert::AreEqual(2, Arr[1], L"Value at index 1 should be 2", LINE_INFO());
			Assert::AreEqual(3, Arr[2], L"Value at index 2 should be 3", LINE_INFO());
		}

	};
}