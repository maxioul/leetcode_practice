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
    long long left = LONG_MIN;
    TreeNode* pre;
    TreeNode* first;
    TreeNode* second;
    void recoverTree(TreeNode* root) {
        
        Find(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        
    }
    void Find(TreeNode* root){
        if(!root){
            return;
        }
        Find(root->left);
        if(root->val<=left){
            if(first==nullptr){
                first = pre;
                second = root;
            }else{
                second = root;
            }
        }
        pre = root;
        left = root->val;
        Find(root->right);
    }
};
