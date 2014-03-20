// Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Interset two sorted arrays
// a[] of size m, b[] of size n
// If the values in the arrays do not overlap, intersection is void
// Allocate c[] of size min(m, n)

// Solution 1
// For all items in the shorter array search the longer one
// O(nlogn)

// Solution 2
// Hash items in the longer array so we can access them by value (O(n))
// Then for each item in the short array (O(m)), look up the hash table (O(1)
// O(m+n)
// Not good if the large array is very large (n is very large)

// Solution 3
// Two pointer approach
// Start at the begining of the arrays.
// for all elements in the arrays
// if a[i] > b[j] j++
// elseif a[i] < b[j] i++
// else c = a[i], i++, j++
// O(m+n)

// http://leetcode.com/2010/03/here-is-phone-screening-question-from.html

const int N = 4;
int arrayA[N] = { 4, 7, 10, 34 };
const int M = 6;
int arrayB[M] = { 7, 8, 9, 10, 23, 34 };
int* intersection = nullptr;

void IntersectArrays(int* a, int aLength, int* b, int bLength, int*& c)
{
	if (a[aLength - 1] < b[0] && b[bLength - 1] < a[0]) return;
	int cLength = min(aLength, bLength);
	c = new int[cLength];
	for (int i = 0, j = 0, k = 0; i < aLength && j < bLength && k < cLength; )
	{
		if (a[i] > b[j]) j++;
		else if (a[i] < b[j]) i++;
		else
		{
			c[k] = a[i];
			i++;
			j++;
			k++;
		}
	}

}

// ONce a match is found, the longer array needs to be searched only from that item on


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

