#include <string>
#include <queue>
#include <cmath>
#include <vector>
#define MAX 101

using namespace std;

// 프로그래머스 전력망을 둘로 나누기
// https://school.programmers.co.kr/learn/courses/30/lessons/86971?language=cpp

int cnt;
vector<int> vCnt[MAX];

void bfs(int v1, int v2){
    queue<int> q;
    vector<bool> visited(MAX);      // 방문한 노드 확인
    
    q.push(v1);
    visited[v1] = true;             // 자른 노드값은 방문한거로 처리
    visited[v2] = true;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i = 0; i < vCnt[x].size(); i++){
            int node = vCnt[x][i];
            
            if(visited[node]) continue;
            
            cnt++;
            q.push(node);
            visited[node] = true;
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX;
    
    for(auto x : wires){                // 각 노드 연결 작업
        vCnt[x[0]].push_back(x[1]);
        vCnt[x[1]].push_back(x[0]);
    }
    
    for(auto x : wires){
        cnt = 1;
        int v1 = x[0];
        int v2 = x[1];
        
        bfs(v1, v2);
        answer = min(answer, abs(2 * cnt - n));
    }
    
    return answer;
}
