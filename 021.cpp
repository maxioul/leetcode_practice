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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* output = nullptr;
        ListNode* main = nullptr;
        ListNode* sub = nullptr;
        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr){
            return l1;
        }
        if(l1->val<=l2->val){
            main = l1;
            sub = l2;
            output = l1;
        }else{
            main = l2;
            sub = l1;
            output = l2;
        }
        ListNode* post = nullptr;
        while(main != nullptr&&sub!=nullptr){
            if(main->val <= sub->val){
                post = main;
                main = main->next;
            }else{
                ListNode* temp = sub;
                sub = sub->next;
                post->next = temp;
                temp->next = main;
                post = temp;
            }
        }
        if(main == nullptr){
            post->next = sub;
        }
        return output;
        
    }
};
