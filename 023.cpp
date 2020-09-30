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
    
    static bool cmp(ListNode* a, ListNode* b){
        if(a==nullptr){
            return true;
        }
        if(b==nullptr){
            return false;
        }
        return a->val>b->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* output =nullptr;
        
        if(lists.empty()){
            return output;
        }
        
        make_heap(lists.begin(),lists.end(),cmp);
        pop_heap(lists.begin(),lists.end(),cmp);
        output = lists.back();
        if(output == nullptr){
            return output;
        }
        ListNode* now = output;
        int size = lists.size()-1;
        lists[size] = lists[size]->next;
        push_heap(lists.begin(),lists.end(),cmp);
        while(1){
            pop_heap(lists.begin(),lists.end(),cmp);
            if(lists[size]==nullptr){
                break;
            }
            now->next = lists[size];
            now = now->next;
            lists[size] = lists[size]->next;
            push_heap(lists.begin(),lists.end(),cmp);
        }
        return output;
    }
};
