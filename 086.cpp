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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr){
            return head;
        }
        ListNode* sb = new ListNode();
        ListNode* bb = new ListNode();
        ListNode* se = sb;
        ListNode* be = bb;
        while(head!=nullptr){
            if(head->val<x){
                se->next = head;
                se = se->next;
            }else{
                be->next = head;
                be=be->next;
            }
            head=head->next;
        }
        be->next = nullptr;
        se->next = bb->next;
        return sb->next;
    }
};
