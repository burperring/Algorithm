#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> n;
vector<pair<int, int>> m;
vector<pair<int, int>> tree;

pair<int, int> createTree(int start, int end, int idx) {
	if (start == end) return tree[idx] = { n[start], n[start] };

	int mid = (start + end) / 2;

	pair<int, int> a = createTree(start, mid, idx * 2);
	pair<int, int> b = createTree(mid + 1, end, idx * 2 + 1);

	int min_value = a.first < b.first ? a.first : b.first;
	int max_value = a.second > b.second ? a.second : b.second;

	return tree[idx] = { min_value, max_value };
}

pair<int, int> findTree(int start, int end, int a, int b, int idx) {
	if (start > b || end < a) return { 1e9, 0 };
	if (a <= start && end <= b) return tree[idx];

	int mid = (start + end) / 2;

	pair<int, int> node1 = findTree(start, mid, a, b, idx * 2);
	pair<int, int> node2 = findTree(mid + 1, end, a, b, idx * 2 + 1);

	int min_value = node1.first < node2.first ? node1.first : node2.first;
	int max_value = node1.second > node2.second ? node1.second : node2.second;

	return { min_value, max_value };
}

void solution() {
	tree.resize(N * 4);
	createTree(0, N - 1, 1);

	for (int i = 0; i < M; i++) {
		int a = m[i].first;
		int b = m[i].second;

		pair<int, int> result = findTree(1, N, a, b, 1);
		cout << result.first << " " << result.second << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int c;
	for (int i = 0; i < N; i++) {
		cin >> c;
		n.push_back(c);
	}

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		m.push_back({ a, b });
	}

	solution();
	
	return 0;
}
