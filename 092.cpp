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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode  *left, *mid,*right,*tail;
        ListNode *front = new ListNode(0,head);
        if(m==n){
            return head;
        }
        if(!head){
            return head;
        }
        for(int i =0;i<m-1;i++){
            front = front->next;
        }
        
        if(front->next){
            left = front->next;
        }else{
            return head;
        }
        if(left)mid = left->next;
        if(mid)right = mid->next;
        tail = left;
        for(int i = m;i<n;i++){
            mid->next = left;
            left = mid;
            mid = right;
            if(right)right = right->next;
        }
        front->next = left;
        if(tail)tail->next = mid;
        if(m==1){
            return front->next;
        }
        return head;
    }
};
