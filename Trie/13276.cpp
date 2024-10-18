#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

// 실패

class Node
{
public:
	Node* childs[26] = { NULL };

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
			if (cur->childs[str[i] - 'a'] != NULL) cur = cur->childs[str[i] - 'a'];
			else
			{
				cur->childs[str[i] - 'a'] = new Node();
				cur = cur->childs[str[i] - 'a'];
			}
		}
	}

	int find(const char* start, const char* end, const char* str)
	{
        int cnt = 0;
        int sNum = 0, eNum = 0;
        bool sb;
		Node* cur = this->root;

		for (int i = 0; i < strlen(str); i++)
		{
            if(cur->childs[str[i] - 'a'] == cur->childs[start[sNum] - 'a']){
                sNum++;
                if(sNum == strlen(start))
                    sb = true;
            }
            else{
                sNum = 0;
            }

            if(cur->childs[str[i] - 'a'] == cur->childs[end[eNum] - 'a']){
                eNum++;
                if(eNum == strlen(end)){
                    if(sb)
                        cnt++;
                    eNum = 0;
                }
            }
            else{
                eNum = 0;
            }

            cur = cur->childs[str[i] - 'a'];
		}

		return cnt;
	}
};

int main(void)
{
	Trie trie;

	char cNumber[2001];
    string sNumber;

    cin >> sNumber;
    strcpy(cNumber, sNumber.c_str());
    trie.insert(cNumber);

    char cStart[2001], cEnd[2001];
    string start, end;

    cin >> start >> end;
    strcpy(cStart, start.c_str());
    strcpy(cEnd, end.c_str());

    int answer = trie.find(cStart, cEnd, cNumber);
    cout << answer << endl;

	return 0;
}
