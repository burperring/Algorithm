#include<iostream>
#include<algorithm>

using namespace std;

string a[20000];
int n;

int getSum(string a) {
	int length = a.length(), sum = 0;
	for (int i = 0; i < length; i++) {
		// ������ ��쿡�� ���Ѵ�.
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0) {
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool compare(string a, string b) {
	// �ΰ��� ���� ����
	if (a.length() < b.length())
		return 1;	// ���̰� ª�ٸ� �켱������ ���δ�.(���� a)
	else if (a.length() > b.length())
		return 0;	// ���̰� ��ٸ� �켱������ �����.(���� a)
	// ���̰� �������
	else {
		int aSum = getSum(a);
		int bSum = getSum(b);
		// ���ڿ� ���ϸ�� ������ ���� �ٸ���
		if (aSum != bSum) {
			return aSum < bSum;
		}
		else {
			return a < b;
		}
	}
}

int main() {
	// ��� �ø��� ��ȣ�� ���ĺ� (A-Z)�� ����(0-9)�� �̷�����ִ�.
	// �ø��� ��ȣ�� ª���ͺ��� ������ �´�.
	// ���� ���̰� ���ٸ� ��� �ڸ����� ���� �������� �����´�.
	// ���� �ڸ����� �յ� ���ٸ� ���ĺ� ���������� ���Ѵ�.
	// (���ڰ� ���ĺ����� ���������� �۴�.)
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