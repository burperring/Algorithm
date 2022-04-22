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
	// �ѽ��� �迭�� int�� string���� �����ش�.
	vector<pair<string, pair<int, int>>>v;
	v.push_back(pair<string, pair<int, int>>("ȫ�浿", pair < int, int>(90, 19520225)));
	v.push_back(pair<string, pair<int, int>>("��¯��", pair < int, int>(85, 19980110)));
	v.push_back(pair<string, pair<int, int>>("������", pair < int, int>(93, 19981225)));
	v.push_back(pair<string, pair<int, int>>("��ö��", pair < int, int>(85, 19981004)));
	v.push_back(pair<string, pair<int, int>>("������", pair < int, int>(79, 19980404)));

	// �迭�� �����Ѵ�.(��������)
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " : " << v[i].second.first << endl;
	}

	return 0;
}