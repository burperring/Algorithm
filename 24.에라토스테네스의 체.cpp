// 소수(Prime Number)를 판별하는 알고리즘

// 소수를 구하는 알고리즘
/*#include<stdio.h>
#include<math.h>

bool isPrimeNumber(int x) {
	int end = (int)sqrt(x);
	for (int i = 2; i <= end; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int main() {
	printf("%d", isPrimeNumber(97));

	return 0;
}*/

#include<stdio.h>

int number = 100000;
int count = 0;
int a[100001];

void primeNumberSieve() {
	for(int i = 2; i <= number; i++) {
		a[i] = i;
	}
	
	for(int i = 2; i <= number; i++) {
		if (a[i] == 0) continue;
		for (int j = i + i; j <= number; j += i) {
			a[j] = 0;
		}
	}

	for (int i = 2; i < number; i++) {
		if (a[i] != 0) {
			printf("%d\t", a[i]);
			count++;
			if (count % 10 == 0)
				printf("\n");
		}
	}
}

int main() {
	primeNumberSieve();

	return 0;
}