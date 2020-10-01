/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* pre = nullptr;
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        if(head->next == nullptr){
            return head;
        }
        if(pre!=nullptr){
            pre->next = head->next;
        }
        ListNode* temp = head->next;
        head->next = temp->next;
        temp->next = head;
        pre = head;
        swapPairs(head->next);
        return temp;
    }
};
