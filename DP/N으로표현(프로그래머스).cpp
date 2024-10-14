#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

// https://ssocoit.tistory.com/43

using namespace std;

int solution(int N, int number) {
    int answer = -1;                // 최솟값이 8보다 크면 -1 리턴
    unordered_set<int> dp[8];       // 정렬할 필요 X -> unordered_set 사용(set 보다 빠르다)
                                    // unordered_set : O(1), set : O(logn)
    int sum = 0;
    for(int i = 0; i < 8; i++){
        sum = sum * 10 + N;         // N, NN, NNN, ... 에 해당하는 수 기입
        dp[i].insert(sum);      
    }
    
    // N 갯수에 따른 각 사칙연산에 대한 합계 구하는 식
    // 1 : N
    // 2 : NN, (N+N, N-N, N*N, N/N)
    // 3 : NNN, (NN+N, NN-N, NN*N, NN/N)
    //          ((N+N)+N, (N+N)-N, (N+N)*N, (N+N)/N)
    //          ((N-N)+N, (N-N)-N, (N-N)*N, (N-N)/N)
    //          ((N*N)+N, (N*N)-N, (N*N)*N, (N*N)/N)
    //          ((N/N)+N, (N/N)-N, (N/N)*N, (N/N)/N)
    // ...
    for(int i = 1; i < 8; i++){
        for(int j = 0; j < i; j++){
            for(int x : dp[j]){
                for(int y : dp[i-j-1]){
                    dp[i].insert(x+y);
                    dp[i].insert(x-y);
                    dp[i].insert(x*y);
                    if(y != 0)
                        dp[i].insert(x/y);
                }
            }
        }
    }
    
    for(int i = 0; i < 8; i++){
        if(dp[i].find(number) != dp[i].end()){
            answer = i+1;
            break;
        }
    }
    
    return answer;
}
