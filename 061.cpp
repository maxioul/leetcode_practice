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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        for(int i = 0;i<k;i++){
            if(fast->next==nullptr){
                fast = head;
                k = k % (i + 1);
                i = -1;
            }else{
                fast = fast->next;
            }
        }
        while(fast->next !=nullptr){
            slow = slow->next;
            fast=fast->next;
        }
        if(slow->next==nullptr){
            return head;
        }
        fast->next = head;
        fast = slow->next;
        slow->next = nullptr;
        return fast;
    }
};
