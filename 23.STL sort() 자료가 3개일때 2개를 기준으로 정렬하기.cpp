#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<string, pair<int, int>>a,
	pair<string, pair<int, int>>b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;
	}
}

int main() {
	// 한쌍의 배열을 int와 string으로 합쳐준다.
	vector<pair<string, pair<int, int>>>v;
	v.push_back(pair<string, pair<int, int>>("홍길동", pair < int, int>(90, 19520225)));
	v.push_back(pair<string, pair<int, int>>("신짱구", pair < int, int>(85, 19980110)));
	v.push_back(pair<string, pair<int, int>>("이유리", pair < int, int>(93, 19981225)));
	v.push_back(pair<string, pair<int, int>>("김철수", pair < int, int>(85, 19981004)));
	v.push_back(pair<string, pair<int, int>>("이훈이", pair < int, int>(79, 19980404)));

	// 배열을 정렬한다.(내림차순)
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " : " << v[i].second.first << endl;
	}

	return 0;
}