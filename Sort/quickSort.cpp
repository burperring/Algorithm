#include<iostream>
#define MAX_SIZE 10;
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))

using namespace std;

// 1. 퀵 정렬은 피벗을 기준으로 2개의 부분 리스트로 나눈다.
// 2. 피벗보다 작은 값은 모두 왼쪽 부분 리스트로, 큰 값은 오른쪽 부분 리스트로 옮긴다.
// 2개의 비균등 배열 list[left...pivot-1]와 list[pivot+1...right]의 합병 과정

int show(int* data, int number){
    for(int i = 0; i < number; i++){
        cout << data[i] <<" ";
    }
}

// 실제 숫자들이 정렬되는 과정
int partition(int* data, int left, int right){
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = data[left]; // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택

    // low와 high가 교차할 때까지 반복(low<high)
    do{
        // list[low]가 피벗보다 작으면 계속 low 증가
        do{
            low++;  // low는 left+1에서 시작
        }while(low <= right && data[low] < pivot);

        // list[high]가 피벗보다 크면 계속 high를 감소
        do{
            high--; // high는 right에서 시작
        }while(high >= left && data[high] > pivot);

        // 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
        if(low < high){
            SWAP(data[low], data[high], temp);
        }
    }while(low < high);

    // low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
    SWAP(data[left], data[high], temp);

    // 피벗의 위치인 high값을 반환
    return high;
}

// 퀵 정렬
void quick_short(int* data, int left, int right){

    // 정렬한 범위가 2개 이상의 데이터면(리스트의 크기가 0, 1이 아니면)
    if(left < right){
        // partition 함수를 호출하여 피벗을 기준으로 리스트를 비균등 분할
        int q = partition(data, left, right);   // q : 피벗의 위치

        // 피벗을 제외한 2개의 부분 리스트를 대상으로 순환 호출
        quick_short(data, left, q-1);   // (left ~ 피벗의 앞)
        quick_short(data, q+1, right);  // (피벗의 뒤 ~ right)
    }
}

int main(){
    int n = MAX_SIZE;
    int data[n] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    // 퀵 정렬 수행
    quick_short(data, 0, n-1);
    show(data, n);
}
