#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, x;
    vector<int> v;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> x;
        v.push_back(x);
    }

    int start = 0, end = 0, answer = 0;
    int sum = v[0];

    while(end < N){
        if(sum < M){
            end++;
            if(end < N)
                sum += v[end];
        }
        else if(sum > M){
            sum -= v[start];
            start++;
        }
        else{
            sum -= v[start];
            start++;
            end++;
            answer++;
            if(end < N)
                sum += v[end];
        }
    }

    cout << answer;
}
