#include <bits/stdc++.h>
using namespace std;

/* 
前缀树（Prefix Tree），也称为字典树（Trie），是一种特殊的树形数据结构，用于存储字符串集合并支持快速的字符串查找、插入和删除操作。
前缀树的每个节点代表一个字符串的前缀，而根节点代表空字符串。
每个节点可以有多个子节点，每个子节点代表一个字符，从根节点到叶节点的路径表示一个字符串。
前缀树的一个重要应用是用于实现自动完成（Autocomplete）功能，如输入搜索关键字时自动提示相关的搜索词条。
 */

// TrieNode: TrieNode 类表示前缀树的节点，包含一个布尔值 is_word 表示该节点是否是一个字符串的末尾节点，以及一个 children 哈希表表示该节点的子节点集合，其中键为字符，值为子节点的指针。
class TrieNode {
public:
    bool is_word;
    unordered_map<char, TrieNode*> children;
    TrieNode() : is_word(false) {}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();  // 初始化根节点
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (auto& ch : word) {
            if (!node->children.count(ch)) {   // Trie中没有该字符，添加字符
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch]; // 移动到下一个字符节点
        }
        node->is_word = true;   // 末尾字符设置为true
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = find(word);
        return node != nullptr && node->is_word == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = find(prefix);
        return node != nullptr;
    }
private:
    TrieNode* root;
    TrieNode* find(string& word) {
        TrieNode* node = root;
        for (auto& ch : word) {
            if (!node->children.count(ch)) {  // Trie中没有该字符，返回空
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
*/

int main() {
    Trie* obj = new Trie();
    string word = "apple";
    obj->insert(word);
    cout << obj->search(word) << endl;
    cout << obj->search("app") << endl;
    cout << obj->startsWith("app") << endl;
    obj->insert("app");
    obj->search("app");
    return 0;
}