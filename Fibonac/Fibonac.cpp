// Fibonac.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <assert.h>
using namespace std;

static const int kMaxFibs = 50;

// Generate Fibonacci numbers
// f(0) = 0
// f(1) = 1
// fn = f(n-1) + f(n-2)
int Fibonacci(int i)
{
	if (0 == i) return 0;
	if (1 == i) return 1;
	return Fibonacci(i - 1) + Fibonacci(i - 2);
}

static int fibs[kMaxFibs] = { 0 };
int GetFib(int n)
{
	assert(n < kMaxFibs);
	assert(0 <= n);
	if (0 == n) return 0;
	if (1 == n) return 1;
	if (fibs[n] != 0) return fibs[n];
	fibs[n - 1] = GetFib(n - 1);
	fibs[n - 2] = GetFib(n - 2);
	fibs[n] = fibs[n - 1] + fibs[n - 2];
	return fibs[n];
}
int Fibonacci2(int n)
{
	return GetFib(n);
}

int _tmain(int argc, _TCHAR* argv[])
{
	for (int i = 0; i < kMaxFibs; i++)
	{
		//cout << Fibonacci(i) << " ";
		cout << Fibonacci2(i) << " ";
	}
	return 0;
}

