#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
vector<int> vBfs;
vector<int> vDfs;
vector<bool> bDfs(MAX);

void bfs(int start){        // 너비 우선 탐색
    queue<int> q;
    vector<bool> c(MAX);

    q.push(start);
    c[start] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        vBfs.push_back(x);

        for(int i = 0; i < a[x].size(); i++){
            int y = a[x][i];
            if(!c[y]){
                q.push(y);
                c[y] = true;
            }
        }
    }
}

void dfs(int start){        // 깊이 우선 탐색
    if(bDfs[start]) return;
    bDfs[start] = true;
    vDfs.push_back(start);

    for(int i = 0; i < a[start].size(); i++){
        int x = a[start][i];
        dfs(x);
    }
}

int main(){
    int dot, cnt, line;
    
    scanf("%d %d %d", &dot, &cnt, &line);

    for(int i = 0; i < cnt; i++){
        int v1, v2;

        scanf("%d %d", &v1, &v2);
        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }

    for(int i = 0; i <= dot; i++){
        sort(a[i].begin(), a[i].end());
    }

    dfs(line);
    bfs(line);

    for(int i = 0; i < vDfs.size(); i++){
        if(i == vDfs.size() - 1)
            cout << vDfs[i] << endl;
        else
            cout << vDfs[i] << " ";
    }

    for(int i = 0; i < vBfs.size(); i++){
        if(i == vBfs.size() - 1)
            cout << vBfs[i];
        else
            cout << vBfs[i] << " ";
    }
}
