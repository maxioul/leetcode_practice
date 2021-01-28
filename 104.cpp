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
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*>pre;
        queue<TreeNode*>next;
        pre.push(root);
        int depth = 0;
        while(!pre.empty()){
            while(!pre.empty()){
                TreeNode* temp = pre.front();
                if(temp->left!=nullptr){
                    next.push(temp->left);
                }
                if(temp->right!=nullptr){
                    next.push(temp->right);
                }
                pre.pop();
            }
            swap(pre,next);
            
            depth++;
        }
        return depth;
    }
};
