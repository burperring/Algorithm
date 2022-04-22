// 1번 문제에서 2 x 2 타일을 추가해서 문제풀기
// D[n] = D[n - 1] + 2 * D[n - 2]

#include<stdio.h>

int d[1001];

int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 3;
	if (d[x] != 0) return d[x];
	return d[x] = (dp(x - 1) + 2 * dp(x - 2)) % 10007;
}

int main() {
	int x;
	scanf_s("%d", &x);
	printf("%d", dp(x));

	return 0;
}
