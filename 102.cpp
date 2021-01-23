/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>>work;
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>pre, next;
        if(root!=nullptr){
            pre.push(root);
            LO(pre,next);
        }
        return work;
    }
    void LO(queue<TreeNode*>&pre,queue<TreeNode*>&next){
        if(pre.empty()){
            return;
        }
        vector<int>temp;
        while(!pre.empty()){
            temp.push_back(pre.front()->val);
            if(pre.front()->left!=nullptr){
                next.push(pre.front()->left);
            }
            if(pre.front()->right!=nullptr){
                next.push(pre.front()->right);
            }
            pre.pop();
        }
        work.push_back(temp);
        LO(next,pre);
    }
};
