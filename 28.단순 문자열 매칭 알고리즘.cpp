#include<iostream>

using namespace std;

int findString(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();

	for (int i = 0; i <= parentSize - patternSize; i++) {
		bool finded = true;
		for (int j = 0; j < patternSize; j++) {
			if (parent[i + j] != pattern[j]) {
				finded = false;
				break;
			}
		}
		if (finded) {
			return i;
		}
	}

	return -1;
}

int main() {
	string parent = "Hello World";
	string pattern = "llo W";
	int result = findString(parent, pattern);

	if (result == -1) {
		cout << "ã�� �� �����ϴ�.";
	}
	else {
		cout << result + 1 << "��°���� ã�ҽ��ϴ�.";
	}

	return 0;
}