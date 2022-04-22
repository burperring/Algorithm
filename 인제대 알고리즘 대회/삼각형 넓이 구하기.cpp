#include<iostream>

using namespace std;

int main() {
	int rt[3][2];
	double size;
	bool check = true;
	double hsize;

	for (int i = 0; i < 3; i++) {
		scanf_s("%d%d", &rt[i][0], &rt[i][1]);
	}

	for (int i = 0; i < 3; i++) {
		if (rt[i][0] > 1000 || rt[i][0] < -1000 || rt[i][1] > 1000 || rt[i][1] < -1000)
			check = false;
	}

	size = (rt[0][0] * rt[1][1] + rt[1][0] * rt[2][1] + rt[2][0] * rt[0][1]) -
		(rt[1][0] * rt[0][1] + rt[2][0] * rt[1][1] + rt[0][0] * rt[2][1]);

	hsize = size / 2;

	if (check == true) {
		if (hsize < 0)
			printf("%.1f", -hsize);
		else if (hsize == 0)
			printf("-1");
		else
			printf("%.1f", hsize);
	}
	else
		printf("-1");

	return 0;
}