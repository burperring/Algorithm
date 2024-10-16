#include<iostream>
#include<algorithm>
#define MAX 2000000000

typedef long long ll;
using namespace std;

ll x, lSize;
ll arr[100001];
ll segTree[10000001];

ll init(int start, int end, int node){
    // start와 end위차가 같은 경우 start 값을 넣어준다.
    if(start == end) return segTree[node] = start;

    int mid = (start + end) / 2;
    int left = init(start, mid, node * 2);
    int right = init(mid + 1, end, node * 2 + 1);

    return segTree[node] = arr[left] < arr[right] ? left : right;
}

ll query(int start, int end, int left, int right, int node){
    if(left > end || right < start) return MAX;                 // 찾는 노드 구간이 안 겹치는 경우
    if(left <= start && end <= right) return segTree[node];     // 찾아야 하는 구간 노드가 포함되는 경우

    int mid = (start + end) / 2;
    int left_index = query(start, mid, left, right, node * 2);
    int right_index = query(mid + 1, end, left, right, node * 2 + 1);

    // 찾아야 하는 구간이 노드 구간에 부분적으로 겹치는 경우
    if(left_index == MAX) return right_index;           // 에러 방지
    else if(right_index == MAX) return left_index;      // 에러 방지
    else return arr[left_index] < arr[right_index] ? left_index : right_index;
}

void solve(long long left, long long right){
    if(left > right) return;

    // 구간내의 최소값과 해당 인덱스 찾기
    long long index = query(0, x - 1, left, right, 1);

    lSize = max(lSize, arr[index] * (right - left + 1));

    solve(left, index - 1);
    solve(index + 1, right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(1){
        lSize = 0;
        cin >> x;

        if(x == 0) break;

        for(int i = 0; i < x; i++){
            cin >> arr[i];
        }

        init(0, x - 1, 1);
        solve(0, x - 1);

        cout << lSize << endl;
    }
}
