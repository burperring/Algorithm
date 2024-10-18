#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

class Node
{
public:
	Node* childs[26] = { NULL };
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
			if (cur->childs[str[i] - 'a'] != NULL) cur = cur->childs[str[i] - 'a'];
			else
			{
				cur->childs[str[i] - 'a'] = new Node();
				cur = cur->childs[str[i] - 'a'];
			}
		}

		cur->isWord = true;
	}

	bool find(const char* str)
	{
		Node* cur = this->root;

		for (int i = 0; i < strlen(str); i++)
		{
			if (cur->childs[str[i] - 'a'] == NULL) return 0;
			else cur = cur->childs[str[i] - 'a'];
		}

		if (cur->isWord) return 1;
		else return 0;
	}
};

int main(void)
{
	Trie trie;

	trie.insert("tree");

	cout << trie.find("tree") << '\n';
	cout << trie.find("tre") << '\n';

	return 0;
}
