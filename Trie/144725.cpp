#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

class AntDen {
private:
    map<string, AntDen*> child; // key : 자식 문자열(다음 문자열)  valuse : 자식 객체 주소 

public:
    /* 트라이 트리 만들기 (재귀로 구현) */
    void Insert(vector<string>& foods, int index) {
        if(index == foods.size()) 
            return;

        if(child.find(foods[index]) == child.end())
            child[foods[index]] = new AntDen();
        child[foods[index]]->Insert(foods, index + 1);
    }

    void Output(int depth) { // DFS
        for(auto& ch : child) {
            for(int i = 0; i < depth; ++i) // 깊이 당 -- 한 번 
                cout << "--";
            cout << ch.first << '\n';
            ch.second->Output(depth + 1);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    AntDen* root = new AntDen();

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        vector<string> foods(k);
        for (int j = 0; j < k; ++j)
            cin >> foods[j];

        root->Insert(foods, 0); // 트라이 트리 만들고
    }

    root->Output(0); // DFS 탐색
}
