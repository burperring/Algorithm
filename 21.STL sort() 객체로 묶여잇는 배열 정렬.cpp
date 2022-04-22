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

	// 정렬 기준은 점수가 작은 순서
	bool operator <(Student& student) {
		return this->score < student.score;
	}
};

int main() {
	Student student[] = {
		Student("홍길동",90),
		Student("김철수",93),
		Student("신짱구",80),
		Student("이유리",87),
		Student("이훈이",62)
	};

	sort(student, student + 5);

	for (int i = 0; i < 5; i++) {
		cout << student[i].name << " : " << student[i].score << endl;
	}

	return 0;
}