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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }
        ListNode*tail = head;
        ListNode*newhead = tail;
        for(int i =0;i<k;i++){
            if(tail == nullptr)return head;
            newhead = tail;
            tail = tail->next;
        }
        if(pre !=nullptr)pre->next = newhead;
        pre = head;
        ListNode* now = head;
        for(int i =0;i<k;i++){
            ListNode* temp = now->next;
            now->next = tail;
            tail = now;
            now = temp;
        }
        reverseKGroup(head->next,k);
        return tail;
    }
};
