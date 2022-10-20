#include <bits/stdc++.h>
using namespace std;

// 1234

// 1423

// 12345
// 15243

struct TreeNode {
    TreeNode* next;
    int val;
    TreeNode(TreeNode* next_, int val_) : next(next_), val(val_) {}
};

TreeNode* reverseList(TreeNode* head) {
    TreeNode* pre = nullptr;
    while (head) {
        TreeNode* post = head->next;
        head->next = pre;
        pre = head;
        head = post;
    }
    return pre;
}

TreeNode* mergeList(TreeNode* L1, TreeNode* L2) {
    TreeNode* cur = L1;
    while (L1 != nullptr && L2 != nullptr) {
        TreeNode* L1post = L1->next;
        TreeNode* L2post = L2->next;
        L1->next = L2;
        L2->next = L1post;
        L1 = L1post;
        L2 = L2post;
    }
    return cur;
}


TreeNode* reorderList(TreeNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    TreeNode* slow = head;
    TreeNode* fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    TreeNode* L1 = head;
    TreeNode* L2 = slow->next;
    slow->next = nullptr;
    L2 = reverseList(L2);

    return mergeList(L1, L2);
}

int main() {



    TreeNode* node5 = new TreeNode(nullptr, 6);
    TreeNode* node4 = new TreeNode(node5, 5);
    TreeNode* node3 = new TreeNode(node4, 4);
    TreeNode* node2 = new TreeNode(node3, 3);

    TreeNode* node1 = new TreeNode(node2, 2);
    TreeNode* head = new TreeNode(node1, 1);
    TreeNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    head = reorderList(head);

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;


    return 0;
}