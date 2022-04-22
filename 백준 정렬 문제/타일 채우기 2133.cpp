// 문제
// 3 x n 크기의 벽을 2 x 1, 1 x 2 크기의 타일로 채우는 경우의 수를 구하시오
// D[n] = 3 * D[n - 2] + 2 * D[n - 4] + 2 * D[n - 6] + ... + 2 * D[0]

#include<stdio.h>

int d[1001];

int dp(int x) {
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (d[x] != 0) return d[x];
	int result = 3 * dp(x - 2);
	for (int i = 3; i <= x; i++) {
		if (i % 2 == 0) {
			result += 2 * dp(x - i);
		}
	}
	return d[x] = result;
}

int main() {
	int x;
	scanf_s("%d", &x);
	printf("%d", dp(x));
}