#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int> > a[7]; // 간선 정보입니다. 
int d[7]; // 최소 비용입니다. 

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int> > pq; // 힙 구조입니다. 
	pq.push(make_pair(start, 0));
	// 가까운 순서대로 처리하므로 큐를 사용합니다.
	while(!pq.empty()) {
		int current = pq.top().first;
		// 짧은 것이 먼저 오도록 음수화(-)합니다. 
		int distance = -pq.top().second;
		pq.pop();
		// 최단 거리가 아닌 경우 스킵합니다. 
		if(d[current] < distance) continue;
		for(int i = 0; i < a[current].size(); i++) {
			// 선택된 노드의 인접 노드 
			int next = a[current][i].first; 
			// 선택된 노드를 인접 노드로 거쳐서 가는 비용 
			int nextDistance = distance + a[current][i].second;
			// 기존의 최소 비용보다 더 저렴하다면 교체합니다. 
			if(nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main(void) {
	// 기본적으로 연결되지 않은 경우 비용은 무한입니다. 
	for(int i = 1; i <= number; i++) {
		d[i] = INF;
	}
	
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));
	
	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));
	
	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));
	
	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));
	
	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));
	
	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));
	
	dijkstra(1);
	
	// 결과를 출력합니다. 
	for(int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
}
