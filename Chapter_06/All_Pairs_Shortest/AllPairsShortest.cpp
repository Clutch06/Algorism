#include <stdio.h>

#define far 10000

int course[5][5] = 
{
	{0, 4, 2, 5, far},
	{far, 0, 1, far, 4},
	{1, 3, 0, 1, 2},
	{-2, far, far, 0, 2},
	{far, -3, 3, 1, 0}
};

void AllPairsShortest(int arr, int n);

int main()
{
	return 0;
}

void AllPairsShortest(int arr, int n)
{
	for (int k = 1; k <= n; k++) 
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{

			}
		}
	}
}