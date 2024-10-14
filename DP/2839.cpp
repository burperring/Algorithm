#include<iostream>

using namespace std;

int d[5000] = {0};

int dp(int x){
    d[7] = -1;
    d[3] = 1;
    d[4] = -1;
    d[5] = 1;

    if(d[x] != 0) return d[x];
    else if(x % 5 == 1 || x % 5 == 2 || x % 5 == 4)
        return d[x] = d[3] + dp(x - 3);
    else if(x % 5 == 3 || x % 5 == 0)
        return d[x] = d[5] + dp(x - 5);
}

int main(){
    int x;

    cin >> x;

    cout << dp(x);
}
