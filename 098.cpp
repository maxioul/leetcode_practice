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
    long long Left = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        bool output = true;
        if(root->left){
            output = output&&isValidBST(root->left);
        }
        if(root->val<=Left){
            return false;
        }
        Left = root->val;
        if(root->right){
            output = output&&isValidBST(root->right);
        }
        return output;
    }
};
