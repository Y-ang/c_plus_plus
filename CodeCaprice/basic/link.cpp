#include<iostream>
using namespace std;

struct LinkNode{
    int val;
    LinkNode* next;
    LinkNode(int x): val(x), next(NULL) {}
};

int main(){
    LinkNode* head = new LinkNode(5);
    cout << head->val;
    return 0;
}