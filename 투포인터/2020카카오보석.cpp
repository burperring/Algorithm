#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> s;
    map<string, int> m;
    
    for(auto x : gems){
        s.insert(x);
    }
    
    int gemCnt = s.size();
    
    int start = 0, end = 0, i = 0;
    int iLen = 100000;
    
    while(1){
        for(i = end; i < gems.size(); i++){
            if(m.find(gems[i]) != m.end()){
                m[gems[i]]++;
            }
            else{
                m.insert({gems[i], 1});
            }
            
            if(m.size() == gemCnt){
                end = i;
                break;
            }
        }
        
        if(i == gems.size())
            break;
        
        for(i = start; i < gems.size(); i++){
            m[gems[i]]--;
            if(m[gems[i]] == 0){
                start = i;
                break;
            }
        }
        
        if(end - start < iLen){
            iLen = end - start;
            answer[0] = start + 1;
            answer[1] = end + 1;
        }
        
        m.erase(gems[start]);
        start++;
        end++;
    }
    
    return answer;
}
