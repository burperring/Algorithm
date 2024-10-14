#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10001

using namespace std;

int n, k;
vector<int> coin;
vector<int> v(10001, MAX);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        coin.push_back(x);
    }

    sort(coin.begin(), coin.end());

    for(auto x : coin){
        v[x] = 1;

        for(int i = x; i < 10001; i++){
            v[i] = min(v[i], v[i-x] + 1);
        }
    }

    if(v[k] == MAX)
        v[k] = -1;
    cout << v[k];
}
