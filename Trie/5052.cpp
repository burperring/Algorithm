#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

class Node
{
public:
	Node* childs[10] = { NULL };
	bool isWord = false;

	Node() {}
};

class Trie
{
public:
	Node* root;

	Trie() { this->root = new Node(); }

	void insert(const char* str)
	{
		Node* cur = this->root;

		for (int i = 0; i < strlen(str); i++)
		{
			if (cur->childs[str[i] - '0'] != NULL) cur = cur->childs[str[i] - '0'];
			else
			{
				cur->childs[str[i] - '0'] = new Node();
				cur = cur->childs[str[i] - '0'];
			}
		}

		cur->isWord = true;
	}

	bool find(const char* str)
	{
		Node* cur = this->root;

		for (int i = 0; i < strlen(str); i++)
		{
			if (cur->childs[str[i] - '0'] == NULL) return 0;
			else{
                cur = cur->childs[str[i] - '0'];
                if(cur->isWord && i != strlen(str) - 1) return 0;
            }
		}

		if (cur->isWord) return 1;
		else return 0;
	}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin.ignore(NULL);

    int t, n;
    char number[10001];
    string sNumber;
    vector<string> vNumber;

    cin >> t;

    for(int i = 0; i < t; i++){
        Trie trie;
        bool isNumber = false;

        cin >> n;

        for(int j = 0; j < n; j++){
            cin >> sNumber;
            vNumber.push_back(sNumber);
            strcpy(number, sNumber.c_str());
            trie.insert(number);
        }

        for(auto x : vNumber){
            strcpy(number, x.c_str());
            if(!trie.find(number)){
                isNumber = true;
                break;
            }
        }

        if(isNumber)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

        vNumber.clear();
    }
}
