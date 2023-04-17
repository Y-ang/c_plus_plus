#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val_, Node* next_) : val(val_), next(next_) {}
};

Node* isExist(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) break;
    }
    if (fast == nullptr || fast->next == nullptr) return nullptr;
    slow = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}


int main () {
    Node* node2 = new Node(2, nullptr);
    Node* node1 = new Node(1, node2);

    Node* head = new Node(0, node1);

    node2->next = head;

    Node* res = isExist(head);
    if (res == nullptr) {
        cout << "null" << endl;
    } else {
        cout << res->val << endl;
    }
    
    

    return 0;
}
x : head -> 1
y : 1 -> meet
z : meet -> 1

x + n (y + z) + y = 2(x + y)

x = (n - 2)y  + (n + 1) z
x = (n - 1) (y + z) + z