#include<iostream>
#include<algorithm>

using namespace std;

string a[20000];
int n;

int getSum(string a) {
	int length = a.length(), sum = 0;
	for (int i = 0; i < length; i++) {
		// 숫자인 경우에만 더한다.
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0) {
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool compare(string a, string b) {
	// 두개의 길이 구별
	if (a.length() < b.length())
		return 1;	// 길이가 짧다면 우선순위를 높인다.(기준 a)
	else if (a.length() > b.length())
		return 0;	// 길이가 길다면 우선순위를 낮춘다.(기준 a)
	// 길이가 같은경우
	else {
		int aSum = getSum(a);
		int bSum = getSum(b);
		// 글자에 포하모딘 숫자의 합이 다르면
		if (aSum != bSum) {
			return aSum < bSum;
		}
		else {
			return a < b;
		}
	}
}

int main() {
	// 모든 시리얼 번호는 알파벳 (A-Z)와 숫자(0-9)로 이루어져있다.
	// 시리얼 번호는 짧은것부터 앞으로 온다.
	// 만약 길이가 같다면 모든 자리수의 합이 작은것이 먼저온다.
	// 만약 자리수의 합도 같다면 알파벳 사전순으로 비교한다.
	// (숫자가 알파벳보다 사전순으로 작다.)
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n, compare);

	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i] == a[i - 1]) {
			continue;
		}
		else {
			cout << a[i] << endl;
		}
	}

	return 0;
}