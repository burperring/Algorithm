#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/49191

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<int> vWin[n + 1];
    vector<int> vLose[n + 1];
    vector<vector<int>> vCnt(n + 1);
    
    for(auto x : results){
        vWin[x[0]].push_back(x[1]);
        vLose[x[1]].push_back(x[0]);
    }
    
    for(int i = 1; i <= n; i++){
        int x = 0;
        queue<int> qw, ql;
        vector<bool> vb(n + 1);
        qw.push(i);
        ql.push(i);
        
        while(!qw.empty()){
            int current = qw.front();
            qw.pop();
            
            for(auto y : vWin[current]){
                if(!vb[y]){
                    vCnt[i].push_back(y);
                    vb[y] = true;
                    qw.push(y);
                }
            }
        }
        
        while(!ql.empty()){
            int current = ql.front();
            ql.pop();
            
            for(auto y : vLose[current]){
                if(!vb[y]){
                    vCnt[i].push_back(y);
                    vb[y] = true;
                    ql.push(y);
                }
            }
        }
    }
    
    for(auto x : vCnt){
        if(x.size() == n - 1)
            answer++;
    }
    
    return answer;
}
