#include<iostream>
#include<vector>
#define MAX 101

using namespace std;

vector<int> a[MAX];
vector<int> vDfs;
vector<bool> c(MAX);

void dfs(int start){
    if(c[start]) return;
    c[start] = true;
    vDfs.push_back(start);

    for(int i = 0; i < a[start].size(); i++){
        int x = a[start][i];
        dfs(x);
    }
}

int main(){
    int comp, cnt;

    cin >> comp;
    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        int v1, v2;

        scanf("%d %d", &v1, &v2);
        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }

    dfs(1);

    cout << vDfs.size() - 1;
}
