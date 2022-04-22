#include<iostream>
#include<string>
#define TEXT_LENGTH 10001

using namespace std;

int main() {
	int x;
	scanf_s("%d", &x);

	char ch[TEXT_LENGTH] = {};
	bool ch_Check[TEXT_LENGTH] = { false };
	int Ccnt[TEXT_LENGTH];
	bool check = true;

	if (x > 10000 || x < 1)
		check = false;

	int CLength = 0;

	cin >> ch;

	for (int i = 0; i < x; i++) {
		int count = 0;
		if (ch_Check[i] == false) {
			char check = ch[i];
			for (int j = i; j < x; j++) {
				if (ch_Check[j] == false) {
					if (ch[i] == ch[j]) {
						count++;
						ch_Check[j] = true;
					}
					else {
						j = x - 1;
					}
				}
			}
		}
		Ccnt[i] = count;
	}

	for (int i = 0; i < x; i++) {
		if (Ccnt[i] != 0) {
			if (Ccnt[i] == 1) {
				CLength += 1;
			}
			else if (Ccnt[i] >= 10 && Ccnt[i] < 100)
				CLength += 3;
			else if (Ccnt[i] >= 100 && Ccnt[i] < 1000)
				CLength += 4;
			else if (Ccnt[i] >= 1000 && Ccnt[i] < 10000)
				CLength += 5;
			else if (Ccnt[i] == 10000)
				CLength += 6;
			else CLength += 2;
		}
	}

	if (ch[x] == NULL && check == true){
		cout << x << " " << CLength << endl;
		cout << (x - CLength) * 100 / x << "%";
	}

	return 0;
}