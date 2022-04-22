#include<iostream>
#include<algorithm>

using namespace std;

string a[20000];
int n;

bool compare(string a, string b) {
	// �ΰ��� ���� ����
	if (a.length() < b.length())
		return 1;	// ���̰� ª�ٸ� �켱������ ���δ�.(���� a)
	else if(a.length() > b.length())
		return 0;	// ���̰� ��ٸ� �켱������ �����.(���� a)
	// ���̰� �������
	else {
		return a < b;	// �ڵ����� ���������� �����ش�.
	}
}

int main() {
	// ���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ ������ ���̰� ª�� �� ���� ���
	// ���� ���̰� ������ ���� ������� ���
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n, compare);

	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i] == a[i - 1]) {
			continue;
		}
		else {
			cout << a[i] << endl;
		}
	}

	return 0;
}