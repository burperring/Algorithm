#include<iostream>
#define MAX 2000000000

typedef long long ll;
using namespace std;

ll N, lSize;
ll arr[100001];
ll segTree[10000001];

ll init(int start, int end, int node){
    if(start == end) return segTree[node] = start;

    int mid = (start + end) / 2;
    int left = init(start, mid, node * 2);
    int right = init(mid + 1, end, node * 2 + 1);

    return segTree[node] = arr[left] < arr[right] ? left : right;
}

ll query(int start, int end, int left, int right, int node){
    if(left > end || right < start) return MAX;
    if(left <= start && end <= right) return segTree[node];
    
    int mid = (start + end) / 2;
    int left_index = query(start, mid, left, right, node * 2);
    int right_index = query(mid + 1, end, left, right, node * 2 + 1);

    if(left_index == MAX) return right_index;
    else if(right_index == MAX) return left_index;
    else return arr[left_index] < arr[right_index] ? left_index : right_index;
}

void solve(long long left, long long right){
    if(left > right) return;

    ll index = query(0, N - 1, left, right, 1);

    lSize = max(lSize, arr[index] * (right - left + 1));

    solve(left, index - 1);
    solve(index + 1, right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    lSize = 0;
    init(0, N - 1, 1);
    solve(0, N - 1);

    cout << lSize;
}
