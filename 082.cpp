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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode *now = head->next;
        ListNode *pre = head;
        ListNode *fill = head;
        ListNode *cut = nullptr;
        ListNode *first = nullptr;
        bool dup = false;
        while(now!=nullptr){
            if(now->val!=pre->val){
                if(dup == false){
                    fill->val=pre->val;
                    if(first==nullptr){
                        first=fill;
                    }
                    cut = fill;
                    fill = fill->next;
                }
                dup = false;
            }else{
                dup = true;
            }
            pre = now;
            now = now->next;
        }
        if(!dup){
            fill->val=pre->val;
            if(first==nullptr){
                first=fill;
            }
            cut = fill;
        }
        if(cut!=nullptr){
            cut->next=nullptr;
        }
        return first;
    }
};
