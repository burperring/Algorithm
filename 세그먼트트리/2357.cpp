#include<iostream>
#define MAX 1000000001
#define MIN -1

using namespace std;

int N, M;
int arr[100001];
pair<int, int> tree[10000001];

pair<int, int> init(int start, int end, int node){
    if(start == end) return tree[node] = make_pair(arr[start], arr[start]);

    int mid = (start + end) / 2;
    pair<int, int> left = init(start, mid, node * 2);
    pair<int, int> right = init(mid + 1, end, node * 2 + 1);

    int low_value = min(left.first, right.first);
    int high_value = max(left.second, right.second);

    return tree[node] = make_pair(low_value, high_value);
}

pair<int, int> findLowHigh(int start, int end, int left, int right, int node){
    if(left > end || right < start) return make_pair(MAX, MIN);
    if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    pair<int, int> pLeft = findLowHigh(start, mid, left, right, node * 2);
    pair<int, int> pRight = findLowHigh(mid + 1, end, left, right, node * 2 + 1);

    return make_pair(min(pLeft.first, pRight.first), max(pLeft.second, pRight.second));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;
    pair<int, int> answer;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    init(0, N - 1, 1);

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        answer = findLowHigh(0, N - 1, a - 1, b - 1, 1);
        cout << answer.first << " " << answer.second << endl;
    }
}
