#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, k;
vector<int> coin;
vector<int> v(10001);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        coin.push_back(x);
    }
    
    for(auto x : coin){
        if(x > k)
            continue;
        v[x]++;     // 해당 코인과 같은 금액은 무조건 1가지의 경우의 수가 존재하므로 1 추가 

        for(int i = x; i <= k; i++){
            v[i] = v[i] + v[i - x];
        }
    }

    cout << v[k];
}
