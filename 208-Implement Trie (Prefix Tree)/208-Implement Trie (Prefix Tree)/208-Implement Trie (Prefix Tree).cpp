// 208-Implement Trie (Prefix Tree).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;

struct TrieNode {
	bool isStr;
	TrieNode* next[26];
	TrieNode(bool is): isStr(is) {
		memset(next,NULL,sizeof(next));
	}
	bool contains(char c) {
		return next[c-'a']!=NULL;
	}
};

class Trie {
public:
	TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
		root = new TrieNode(false);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int index = 0;
		TrieNode* current = root;
		for (unsigned int i = 0; i < word.size(); i++) {
			if(!current->contains(word[i])) current->next[word[i]-'a'] = new TrieNode(false);
			current = current->next[word[i]-'a'];
			if (i == word.size()-1) current->isStr = true;
		}
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int index = 0;
		TrieNode* current = root;
		for (unsigned int i = 0; i < word.size(); i++) {
			if(!current->contains(word[i])) return false;
			current = current->next[word[i]-'a'];
			if (i == word.size()-1 && current->isStr==false) return false;
		}
		return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int index = 0;
		TrieNode* current = root;
		for (unsigned int i = 0; i < prefix.size(); i++) {
			if(!current->contains(prefix[i])) return false;
			current = current->next[prefix[i]-'a'];
		}
		return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int _tmain(int argc, _TCHAR* argv[])
{
	Trie obj;
	obj.insert("ab");
	obj.search("a");
	obj.startsWith("a");
	return 0;
}

