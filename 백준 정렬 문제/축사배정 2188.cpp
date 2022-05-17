#include <iostream>
#include <vector>
#define MAX 201

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n, m, s;

// 매칭에 성공한 경우 True, 실패한 경우 False 
bool dfs(int x) {
	// 연결된 모든 노드에 대해서 들어갈 수 있는지 시도 
	for(int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		// 이미 처리한 노드는 더 이상 볼 필요가 없음 
		if(c[t]) continue;
		c[t] = true;
		// 비어있거나 점유 노드에 더 들어갈 공간이 있는 경우 
		if(d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &s);
		for(int j = 1; j <= s; j++) {
			int t;
			scanf("%d", &t);
			a[i].push_back(t);
		}
	}
	int count = 0;
	for(int i = 1; i <= n; i++) { // 최대한 우겨 넣습니다. 
		fill(c, c + MAX, false);
		if(dfs(i)) count++;
	}
	printf("%d\n", count);
	return 0;
}
