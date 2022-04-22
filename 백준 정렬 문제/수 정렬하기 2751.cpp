#include<stdio.h>

int number, data[1000001];

void quickSort(int* data, int start, int end) {
	if (start >= end) {	// 원소가 1개인 경우
		return;
	}

	int key = start;	// 키는 첫 번째 원소
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {	// 엇갈릴때까지 반복
		while (data[i] <= data[key]) {	// 키 값보다 큰 값을 만날 때까지
			i++;
		}
		while (data[j] >= data[key] && j > start) {	// 키 값보다 작은 값을 만날 때까지
			j--;
		}
		if (i > j) {	// 현재 엇갈린 상태라면 키값과 교체
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}

	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main(void)
{
	scanf_s("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf_s("%d", &data[i]);
	}

	quickSort(data, 0, number - 1);

	for (int i = 0; i < number; i++)
	{
		printf("%d\n", data[i]);
	}

	return 0;
}