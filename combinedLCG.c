#include <stdio.h>

#define A 48271ULL
#define B 831ULL
#define C 0ULL
#define M 2147483647ULL
#define N 2147483647ULL

unsigned long long int xn;

double combinedLCG(void) {
	unsigned long long int xnn;
	double real_rand;

	xnn = (A * xn + C) % M;
	xn = xnn;
	real_rand = (double)xn / (M - 1);

	return real_rand;
}

int main(void)
{
	unsigned int i, j, class;
	unsigned long long int xnn;
	double rand;
	float interval1, interval2;
	int count[11] = { 0 };
	int mil;

	mil = 1;

	interval1 = 0.000;
	interval2 = 0.100;

	xn = B;
	i = 0;

	printf("  =====================================================\n");
	printf("               混合合法による一様乱数生成\n\n");
	printf("       (a = %llu, b = %llu, c = %llu, M = %llu)\n", A, B, C, M);
	printf("  =====================================================\n");

	printf("\n 【乱数生成進歩状況】\n\n");

	while (i < N) {
		rand = combinedLCG();

		class = (int)(rand * 10);
		count[class]++;

		if (i == N - 1) {
			count[9] = count[9] + count[10];
		}

		i = i + 1;

		if (i % 100000000 == 0) {
			if (mil < 10) {
				printf(" ");
			}
			printf("   %d億個生成...\n", mil);
			mil++;
		}
	}

	printf("\n");
	printf("【度数】\n\n");

	for (j = 0; j <= 9; j++) {
		if (j == 9) {
			printf("  %.3f <= x <= %.3f   %d \n\n", interval1, interval2, count[j]);
			printf("  度数の合計: %d個\n\n", i);
		}
		else {
			printf("  %.3f <= x <  %.3f   %d \n", interval1, interval2, count[j]);
		}
		interval1 = interval2;
		interval2 += 0.100;
	}

	return 0;
}
