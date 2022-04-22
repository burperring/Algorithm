#include<iostream>
#include<vector>
#include<queue>
#define MAX 501

using namespace std;

int n, inDegree[MAX], time[MAX], result[MAX];
vector<int> a[MAX];

void topologySort() {
	queue<int> q;

	// ���� ������ 0�� ��带 ť�� �����մϴ�.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			result[i] = time[i];
			q.push(i);
		}
	}

	// ������ ������ ����Ƿ��� ��Ȯ�� n���� ��带 �湮�մϴ�.
	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			result[y] = max(result[y], result[x] + time[y]);
			// ���Ӱ� ���������� 0�̵� ������ ť�� �����մϴ�.
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << result[i] << endl;
	}
}

int main() {
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &time[i]);
		while (1) {
			int x;
			scanf_s("%d", &x);
			if (x == -1) break;
			inDegree[i]++;
			a[x].push_back(i);
		}
	}
	topologySort();
}