
// class shared_ptr {
// private:
//     int* cnt;
//     int* ptr;
// public:
//     shared_ptr(int cnt_ = 0, int* ptr = nullptr): cnt(cnt_), ptr(nullptr) {}
//     shared_ptr& operator = (const shared_ptr& s) {
//         if (this != &s) {
//             if (--(*(this->cnt)) == 0) {
//                 delete this->ptr;
//                 delete this->cnt;
//             } 

//             ptr = s.ptr;
//             cnt = s.cnt;
//             *(cnt)++;
//         }
//         return *this;
//     }
//     shared_ptr(const shared_ptr& s) : ptr(s.ptr), cnt(s.cnt) {
//         (*cnt)++;
//     }
//     ~shared_ptr() {
//         if (cnt == 0) {
//             delete ptr;
//             ptr = nullptr;
//             cnt = 0;
//         }
//     }

// };


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int val_, Node* left_, Node* right_) : val(val_), left(left_), right(right_) {}
};

void output(unordered_map<Node*, vector<Node*>> umap) {
    for (auto node: umap) {
        cout << node.first->val << endl;
        for (auto& father : node.second) {
            cout << father->val << " ";
        }
        cout << endl;
    }
}


void search(Node* root) {
    queue<Node*> que;
    unordered_map<Node*, vector<Node*>> nodemap;

    if (root) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        while (size--) {
            Node* cur = que.top();
            que.pop();
            if (cur->left) {
                if (nodemap.find(cur->left) != nodemap.end()) {
                    nodemap[cur->left].push_back(cur);
                } else {
                    nodemap[cur->left] = {cur};
                }
                que.push(cur->left);
            }
            if (cur->right) {
                if (nodemap.find(cur->right) != nodemap.end()) {
                    nodemap[cur->right].push_back(cur);
                } else {
                    nodemap[cur->right] = {cur};
                }
                que.push(cur->right);
            }
        }

    }

    output(nodemap);

}


int main() {
    Node* head;
    return 0;
}
