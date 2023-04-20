#include<bits/stdc++.h>
using namespace std;

// 字典树节点
struct TrieNode {
    bool is_word;
    unordered_map<char, TrieNode*> children;
    TrieNode() : is_word(false) {}
};


class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (auto& ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->is_word = true;
    }
    
    bool search(string word) {
       TrieNode* node = find(word);
       return node != nullptr && node->is_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = find(prefix);
        return node != nullptr;
    }
private:
    TrieNode* root;
    TrieNode* find(string& word) {
        TrieNode* node = root;
        for (auto& ch : word) {
            if (!node->children.count(ch)) {
                return nullptr;
            }
            node = node->children[ch];  // 进入子节点，开始下一次判断
        }
        return node;
    }
};

int main() {
    Trie* obj = new Trie();
    string word = "apple";
    obj->insert(word);
    cout << obj->search("apple") << endl;
    cout << obj->search("app") << endl;
    cout << obj->startsWith("app") << endl;
    return 0;
}