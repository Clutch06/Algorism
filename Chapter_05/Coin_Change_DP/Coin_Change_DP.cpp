#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define MONEY 10000

void CoinChange(int n, int coin[]);

int D[5] = { 500, 100, 50, 10, 1 };
int C[MONEY + 1];

int main()
{
	CoinChange(MONEY, D);

	printf("%d\n", C[MONEY] == INF ? -1 : C[MONEY]);
	
	return 0;
}

void CoinChange(int n, int D[])
{
	for (int i = 1; i <= n; i++)
		C[i] = INF;

	C[0] = 0;

	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= 5; i++)
		{
			if (D[i-1] <= j && C[j - D[i-1]] + 1 < C[j])
				C[j] = C[j - D[i-1]] + 1;
		}
	}
}