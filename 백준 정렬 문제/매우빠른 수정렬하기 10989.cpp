#include<iostream>

using namespace std;

int n;
int a[10001];

int main() {
	// 1 <= N <= 10,000,000만큼 수가 주어진다.
	// 이 수는 10,000보다 작거나 같은 자연수이다.
	// 계수정렬 알고리즘을 이용해서 풀기
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}

	for (int i = 0; i < 10001; i++) {
		while (a[i] != 0) {
			cout << i << endl;
			a[i]--;
		}
	}

	return 0;
}