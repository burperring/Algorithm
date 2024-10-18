#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

/*int main(){
    int list[10] = {1, 9, 2, 4, 5, 3, 8, 6, 7, 0};

    sort(list, list+10);            // 기본적인 오름차순 정렬
}*/

bool compare(int a, int b){
    return a < b;
}

int main(){
    vector<int> iVector = {1, 9, 2, 4, 5, 3, 8, 6, 7, 0};

    sort(iVector.begin(), iVector.end());                                   // 기본적인 오름차순 정렬
    sort(iVector.begin(), iVector.end(), less<>());                         // 오름차순 정렬(default)
    sort(iVector.begin(), iVector.end(), greater<>());                      // 내림차순 정렬
    sort(iVector.begin(), iVector.end(), compare);                          // 사용자 정의 정렬
    iVector.erase(unique(iVector.begin(), iVector.end()), iVector.end());   // Vector 중복 제거 작업
}
