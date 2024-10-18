#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/49189

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<int> v[n + 1];
    vector<int> dist(n + 1, -1);
    queue<int> q;
    
    for(auto x : edge){
        v[x[0]].push_back(x[1]);
        v[x[1]].push_back(x[0]);
    }
    
    dist[1] = 0;
    q.push(1);
    
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        for(auto x : v[current]){
            if(dist[x] == -1){
                dist[x] = dist[current] + 1;
                q.push(x);
            }
        }
    }
    
    int max = *max_element(dist.begin(), dist.end());
    answer = count(dist.begin(), dist.end(), max);
    
    return answer;
}
