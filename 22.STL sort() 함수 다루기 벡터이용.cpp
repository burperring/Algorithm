#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	// �ѽ��� �迭�� int�� string���� �����ش�.
	vector<pair<int, string>>v;
	v.push_back(pair<int, string>(90, "ȫ�浿"));
	v.push_back(pair<int, string>(85, "��¯��"));
	v.push_back(pair<int, string>(82, "������"));
	v.push_back(pair<int, string>(98, "��ö��"));
	v.push_back(pair<int, string>(79, "������"));

	// �迭�� �����Ѵ�.(��������)
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		//	������ �ι�° ��(�̸�)	������ ù��° ��(����)
		cout << v[i].second << " : " << v[i].first << endl;
	}

	return 0;
}