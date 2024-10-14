#include <string>
#include <cmath>
#include <vector>
#define MAX 101

using namespace std;

// 프로그래머스 전력망을 둘로 나누기
// https://school.programmers.co.kr/learn/courses/30/lessons/86971?language=cpp

vector<int> vCnt[MAX];

int dfs(int check, int now, int cnt){
    for(int i = 0; i < vCnt[now].size(); i++){
        if(vCnt[now][i] != check){
            cnt = dfs(now, vCnt[now][i], cnt + 1);
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX;
    
    for(auto x : wires){
        vCnt[x[0]].push_back(x[1]);
        vCnt[x[1]].push_back(x[0]);
    }
    
    for(auto x : wires){
        int v1 = x[0];
        int v2 = x[1];
        
        int sum = dfs(v1, v2, 1);
        answer = min(answer, abs(2 * sum - n));
    }
    
    return answer;
}
