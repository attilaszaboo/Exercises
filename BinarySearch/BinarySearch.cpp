// BinarySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Returns the index of number within array a or -1 if not found
int BinarySearch(const int a[], int number, int low, int high)
{
	if (low < 0 || high < 0) return -1;
	if (low > high) return -1;

	int mid = (low + high) / 2;
	if (number == a[mid]) return mid;
	else if (number < a[mid])
		return BinarySearch(a, number, low, mid - 1);
	else // number > a[mid]
		return BinarySearch(a, number, mid + 1, high);
}

int BinarySearchIterative(const int a[], int number, int low, int high)
{
	if (low < 0 || high < 0) return -1;
	if (low > high) return -1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (number == a[mid]) return mid;
		else if (number < a[mid])
			high = mid - 1;
		else // number > a[mid]
			low = mid + 1;
	}
	return -1;

}

static const int kSize = 9;
static const int a[kSize] = { 3, 6, 9, 21, 34, 36, 76, 100, 101 };
int _tmain(int argc, _TCHAR* argv[])
{
	int i = BinarySearch(a, 101, 0, kSize);
	i = BinarySearch(a, 76, 0, kSize);

	i = BinarySearchIterative(a, 77, 0, kSize);
	i = BinarySearchIterative(a, 3, 0, kSize);
	i = BinarySearchIterative(a, 101, 0, kSize);
	i = BinarySearchIterative(a, 76, 0, kSize);
	return 0;
}

