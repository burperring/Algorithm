// Vector 이용시 메모리 초과 발생
// Array 로 값 변경해서 결과 찾기
#include<iostream>
#include<vector>

typedef long long ll;
using namespace std;

vector<ll> v;
vector<ll> tree(40000004);

ll init(int start, int end, int node){
    if(start == end) return tree[node] = v[start];

    int mid = (start + end) / 2;

    // 재귀적으로 두 부분으로 나눈 뒤에ㅔ 그 합을 자기 자신으로 한다.
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// lfet, right : 구간 핪을 구하고자 하는 범위
ll sum(int start, int end, int node, int left, int right){
    // 범위 밖에 있는 경우
    if(left > end || right < start) return 0;

    // 범위 안에 있는 경우
    if(left <= start && end <= right) return tree[node];

    // 그렇지 않을 경우 두 부분으로 나누어 합을 구하기
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// index : 수정하고자 하는 노드
// change : 수정하고자 하는 값
void update(int start, int end, int node, int index, ll change){
    // 수정하고자 하는 노드가 범위 밖에 있는 경우
    if(index < start || index > end) return;

    // 범위 안에 있으면 값 변경, 내려가며 다른 원소 갱신
    tree[node] += change;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, change);
    update(mid + 1, end, node * 2 + 1, index, change);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, K;

    cin >> N >> M >> K;

    for(int i = 0; i < N; i++){
        ll x; cin >> x;
        v.push_back(x);
    }

    init(0, N - 1, 1);

    for(int i = 0; i < M + K; i++){
        ll a1, b2, c3;
        cin >> a1 >> b2 >> c3;

        if(a1 == 1){        // 구간 값 변경
            ll x = c3 - v[b2 - 1];
            update(0, N - 1, 1, b2 - 1, x);
        }
        else if(a1 == 2){   // 구간 합 구하기
            ll iSum = sum(0, N - 1, 1, b2 - 1, c3 - 1);
            cout << iSum << endl;
        }
    }
}

