#include<iostream>
#include<vector>
#define MAX 50001

using namespace std;

int iCount = 0;
int cnt, line;
vector<int> a[MAX];
vector<int> dfs;
vector<bool> b(MAX);

void nonCountDfs(int start);
void CountDfs(int start);
int NewStart();

void nonCountDfs(int start){
    if(dfs.size() == cnt) return;
    if(b[start]) return;
    b[start] = true;
    dfs.push_back(start);
}

void CountDfs(int start){
    if(dfs.size() == cnt) return;
    if(!b[start]){
        b[start] = true;
        dfs.push_back(start);
    }

    int reStart = 0;

    for(int i = 0; i < a[start].size(); i++){
        int x = a[start][i];
        nonCountDfs(x);
    }

    a[start].erase(a[start].begin(), a[start].end());
    reStart = NewStart();
    CountDfs(reStart);

    iCount++;
}

int NewStart(){
    int start = 0;

    for(int i = 1; i <= cnt; i++){
        int x = a[i].size();
        if(x == 0) continue;
        start = max(start, x);
    }

    return start;
}

int main(){
    int start = 0;

    scanf("%d", &cnt);
    line = cnt - 1;

    for(int i = 0; i < line; i++){
        int v1, v2;

        scanf("%d %d", &v1, &v2);
        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }

    start = NewStart();
    CountDfs(start);

    cout << iCount;
}
