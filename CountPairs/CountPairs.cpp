// CountPairs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

static int getMaxCouple(char aa[])
{
	char garbageChar = (char)-1;
	int len = aa.length;
	int prev = 0;
	int i = 1;
	int count = 0;
	while (i<len && prev >= 0)
	{
		if (aa[prev] != aa[i])
		{
			prev++;
			char t = aa[prev];
			aa[prev] = aa[i];
			aa[i] = t;
			i++;
		}
		else
		{
			if (i<len && aa[prev] == aa[i])
			{
				aa[i] = garbageChar;
				i++;
			};
			aa[prev] = garbageChar;
			count++;
			prev--;
		}
	}

	return count;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

