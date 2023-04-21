#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool is_word;
    unordered_map<char, Node*> children;
    Node() : is_word(false) {}
};

class Trie {
private:
    Node* root;
    Node* find(string word) {
        Node* node = root;
        for (auto& ch : word) {
            if (!node->children.count(ch)) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() {
        root = new Node();
    }
    void insertString(string word) {
        Node* node = root;
        for (auto& ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new Node();
            }
            node = node->children[ch];
        }
        node->is_word = true;
    }
    void collectWord(vector<string>& res, string& path, Node* node) {
        if (node == nullptr) {
            return;
        }
        for (auto it = node->children.begin(); it != node->children.end(); it++) {
            char ch = it->first;
            path += ch;
            res.push_back(path);
            collectWord(res, path, (*it).second);
            path.pop_back();
        }
    }
    vector<string> matchPrefix(string word) {
        Node* node = find(word);
        if (node == nullptr) return {};
        vector<string> res{word};
        collectWord(res, word, node);
        return res;
    }

};

int main () {
    Trie* obj = new Trie();
    obj->insertString("apple");
    obj->insertString("app");
    obj->insertString("appl");
    obj->insertString("djehuiw");
    vector<string> res = obj->matchPrefix("app");
    for (auto& str : res) {
        cout << str << endl;
    }
    return 0;
}