#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

int minResult = INT_MAX;
vector<int> vMove;
vector<pair<int, int>> vCase;

bool cmp(vector<int> a, vector<int> b){
    return a.back() < b.back();
}

void move(pair<int, int> p1, pair<int, int> p2, int num, int sum, vector<int> v){
    if(sum > minResult) return;

    if(num == vCase.size()){
        if(minResult > sum){
            minResult = sum;
            vMove = v;
        }

        minResult = minResult > sum ? sum : minResult;
        return;
    }

    int iP1 = p1.first + p1.second;
    int iP2 = p2.first + p2.second;
    int iCase = vCase[num].first + vCase[num].second;

    vector<int> v1 = v;
    v1.push_back(1);
    vector<int> v2 = v;
    v2.push_back(2);

    move(vCase[num], p2, num + 1, sum + abs(iCase - iP1), v1);
    move(p1, vCase[num], num + 1, sum + abs(iCase - iP2), v2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, w;
    vector<int> v;

    cin >> n >> w;
    pair<int, int> p1 = make_pair(1, 1);
    pair<int, int> p2 = make_pair(n, n);

    for(int i = 0; i < w; i++){
        int x, y;
        cin >> x >> y;
        vCase.push_back(make_pair(x, y));
    }

    

    move(p1, p2, 0, 0, v);

    cout << minResult << endl;

    for(auto x : vMove){
        cout << x << endl;
    }
}
