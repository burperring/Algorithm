#include <iostream>
#include <math.h>

using namespace std;

int N, R, C;
int ans = 0;

void solve(int n, int r, int c) {
	if(n == 2) {
		if(r == R && c == C) {
			cout << ans;
			return;
		}
		ans++;
		if(r == R && c + 1 == C) {
			cout << ans;
			return;
		}
		ans++;
		if(r + 1 == R && c == C) {
			cout << ans;
			return;
		}
		ans++;
		if(r + 1 == R && c + 1 == C) {
			cout << ans;
			return;
		}
		ans++;
		return;
	}
	solve(n / 2, r, c);
	solve(n / 2, r, c + n / 2);
	solve(n / 2, r + n / 2, c);
	solve(n / 2, r + n / 2, c + n / 2);
}

int main(void) {
	cin >> N >> R >> C;
	solve(pow(2, N), 0, 0);
	return 0;
}
