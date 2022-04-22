#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	// 한쌍의 배열을 int와 string으로 합쳐준다.
	vector<pair<int, string>>v;
	v.push_back(pair<int, string>(90, "홍길동"));
	v.push_back(pair<int, string>(85, "신짱구"));
	v.push_back(pair<int, string>(82, "이유리"));
	v.push_back(pair<int, string>(98, "김철수"));
	v.push_back(pair<int, string>(79, "이훈이"));

	// 배열을 정렬한다.(오름차순)
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		//	벡터의 두번째 값(이름)	벡터의 첫번째 값(점수)
		cout << v[i].second << " : " << v[i].first << endl;
	}

	return 0;
}