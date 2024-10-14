#include<iostream>

using namespace std;

int d[12] = { 0 };

int dp(int check){
    if(check == 1) return 1;
    if(check == 2) return 2;
    if(check == 3) return 4;

    if(d[check] != 0) return d[check];

    return d[check] = dp(check-1) + dp(check-2) + dp(check-3);
}

int main(){
    int a;

    cin >> a;

    for(int i = 0; i < a; i++){
        int check;

        cin >> check;

        cout << dp(check) << endl;
    }

    return 0;
}
