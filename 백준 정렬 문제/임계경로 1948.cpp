// 월드 나라는 모든 도로가 일방통행인 도로이고, 싸이클이 없다
// => 위상정렬이 수행가능한 기본조건
// 일을 다 마치고 도착 도시에서 모두 다 만나기로 하였다.
// 이때 어떤 사람은 이 시간에 만나기 위해 1분도 쉬지 않고 달려야 하는 사람이 있다.
// => 임계경로를 의미
// 이런 사람들이 지나는 도로의 수를 카운트 하라
// => 임계경로를 구한후 속한 경로의 수를 구하는 프로그램

#include<iostream>
#include<vector>
#include<queue>
#define MAX 10001

using namespace std;

class Edge {
public:
	int node;
	int time;
	Edge(int node, int time) {
		this->node = node;
		this->time = time;
	}
};

int n, start, finish;
int inDegree[MAX], result[MAX], c[MAX];
vector<Edge> a[MAX];
vector<Edge> b[MAX];

void topologySort() {
	queue<int> q;
	// 시작점 노드를 큐에 삽입합니다.
	q.push(start);

	// 더이상 방문할 노드가 없을 때까지
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			Edge y = Edge(a[x][i].node, a[x][i].time);
			if (result[y.node] <= y.time + result[x]) {
				result[y.node] = y.time + result[x];
			}

			// 새롭게 진입차수가 0이 된 정점을 큐에 삽입
			if (--inDegree[y.node] == 0) {
				q.push(y.node);
			}
		}
	}

	// 결과를 역추적합니다.
	int count = 0;
	q.push(finish);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < b[y].size(); i++) {
			Edge x = Edge(b[y][i].node, b[y][i].time);

			// 최장 경로에 포함되는 간선인지 확인
			if (result[y] - result[x.node] == x.time) {
				count++;

				// 큐에는 한 번씩 담아 추적한다.
				if (c[x.node] == 0) {
					q.push(x.node);
					c[x.node] = 1;
				}
			}
		}
	}
	cout << result[finish] << "\n" << count;
}

int main() {
	int m;
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, node, time;
		scanf_s("%d %d %d", &x, &node, &time);
		a[x].push_back(Edge(node, time));
		b[node].push_back(Edge(x, time));
		inDegree[node]++;
	}

	scanf_s("%d %d", &start, &finish);
	topologySort();

	return 0;
}