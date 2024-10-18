#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef struct Trie {
	bool isFinished;
	map<char, Trie> child;
};

void insert(Trie &node, string &word, int idx) {

	if (idx == word.size()) {
		node.isFinished = true;
		return;
	}
	if (node.child.count(word[idx]) == 0) {
		node.child[word[idx]] = Trie();
		node.child[word[idx]].isFinished = false;
	}
	insert(node.child[word[idx]], word, idx + 1);
}

int inputCount(Trie &node, string &word, int idx) {
	if (idx == word.size()) {
		return 0;
	}
	else if (node.child.size() > 1 || idx == 0) {
		return inputCount(node.child[word[idx]], word, idx + 1) + 1;
	}
	else if (node.child.size() == 1 && node.isFinished == true) {
		return inputCount(node.child[word[idx]], word, idx + 1) + 1;
	}
	else
		return inputCount(node.child[word[idx]], word, idx + 1);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;

	while (cin >> n) {

		vector <string> words;
		int sum = 0;

		Trie trie;
		for (int i = 0; i < n; i++) {
			string word;
			cin >> word;
			words.push_back(word);
			insert(trie, word, 0);
		}
		for (int i = 0; i < words.size(); i++) {
			sum += inputCount(trie, words[i], 0);
		}
		cout << fixed;
		cout.precision(2);
		cout << double(sum)/words.size() << "\n";
	}
}
