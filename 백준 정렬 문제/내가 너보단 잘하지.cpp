#include<iostream>
#define INT_STUDENT 1000

using namespace std;

int STd[INT_STUDENT][INT_STUDENT];
double Count[INT_STUDENT] = { 0 };
double AvgCount[INT_STUDENT];
double Avg[INT_STUDENT];

int main() {
	int x, y, score;
	double total = 0;
	scanf_s("%d", &x);

	for (int i = 0; i < x; i++) {
		scanf_s("%d", &y);
		Count[i] = y;
		for (int j = 0; j < y; j++) {
			scanf_s("%d", &score);
			if (score > 100 || score < 0) {
				j--;
			}
			STd[i][j] = score;
		}
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < Count[i]; j++) {
			total += STd[i][j];
		}
		Avg[i] = total / Count[i];
		total = 0;
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < Count[i]; j++) {
			if (STd[i][j] > Avg[i]) {
				AvgCount[i]++;
			}
		}
	}

	for (int i = 0; i < x; i++) {
		printf("%.3f", AvgCount[i] / Count[i] * 100);
		cout << "%" << endl;
	}

	return 0;
}