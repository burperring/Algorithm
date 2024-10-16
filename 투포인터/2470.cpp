#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, x;
    vector<int> v;
    vector<int> answer(2);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int start = 0, end = v.size() - 1;
    int sum = 2000000000;

    while(start < end){
        if(v[start] + v[end] == 0){
            answer[0] = v[start];
            answer[1] = v[end];
            break;
        }
        else if(abs(v[start] + v[end]) < sum){
            sum = abs(v[start] + v[end]);
            answer[0] = v[start];
            answer[1] = v[end];
        }

        if(v[start] + v[end] > 0){
            end--;
        }
        else{
            start++;
        }
    }

    cout << answer[0] << " " << answer[1];
}
