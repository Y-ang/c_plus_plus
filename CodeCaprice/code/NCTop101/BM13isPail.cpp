/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
//         ListNode* cur = head;
//         vector<int> vec;
//         while (cur) {
//             vec.push_back(cur->val);
//             cur = cur->next;
//         }
//         for (int left = 0, right = vec.size() - 1; left < right; left++, right--) {
//             if (vec[left] != vec[right]) return false;
//         }
//         return true;
        ListNode* mid = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            mid = mid->next;
        }
        mid = reverseList(mid);
        while (mid && head) {
            if (mid->val != head->val) {
                return false;
            }
            mid = mid->next;
            head = head->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pre = nullptr;
        while (head) {
            ListNode* post = head->next;
            head->next = pre;
            pre = head;
            head = post;
        }
        return pre;
    }
};