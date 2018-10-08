#include <stdio.h>

int CoinChange(int change);

int main()
{
	int change;
	printf("거스름돈의 액수를 입력하시오 : ");
	scanf("%d", &change);

	int num_coin = CoinChange(change);

	printf("거스름돈에 필요한 최소 동전수 : %d", num_coin);

	return 0;
}

int CoinChange(int change)
{
	int W = change;
	int n500 = 0;
	int n100 = 0;
	int n50 = 0;
	int n10 = 0;
	int n1 = 0;

	while (W >= 500) {
		W = W - 500;
		n500++;
	}

	while (W >= 100) {
		W = W - 100;
		n100++;
	}

	while (W >= 50) {
		W = W - 50;
		n50++;
	}

	while (W >= 10) {
		W = W - 10;
		n10++;
	}

	while (W >= 1) {
		W = W - 1;
		n1++;
	}

	return (n500 + n100 + n50 + n10 + n1);
}