#include<iostream>
#include<algorithm>

using namespace std;

string a[20000];
int n;

bool compare(string a, string b) {
	// 두개의 길이 구별
	if (a.length() < b.length())
		return 1;	// 길이가 짧다면 우선순위를 높인다.(기준 a)
	else if(a.length() > b.length())
		return 0;	// 길이가 길다면 우선순위를 낮춘다.(기준 a)
	// 길이가 같은경우
	else {
		return a < b;	// 자동으로 사전순으로 비교해준다.
	}
}

int main() {
	// 알파벳 소문자로 이루어진 N개의 단어가 들어오면 길이가 짧은 것 부터 출력
	// 만약 길이가 같으면 사전 순서대로 출력
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