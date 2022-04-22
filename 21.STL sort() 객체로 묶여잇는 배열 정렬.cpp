#include<iostream>
#include<algorithm>
using namespace std;

class Student {
public :
	string name;
	int	score;

	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	// ���� ������ ������ ���� ����
	bool operator <(Student& student) {
		return this->score < student.score;
	}
};

int main() {
	Student student[] = {
		Student("ȫ�浿",90),
		Student("��ö��",93),
		Student("��¯��",80),
		Student("������",87),
		Student("������",62)
	};

	sort(student, student + 5);

	for (int i = 0; i < 5; i++) {
		cout << student[i].name << " : " << student[i].score << endl;
	}

	return 0;
}