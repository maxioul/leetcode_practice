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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return isTwoSym(root->left,root->right);
    }
    bool isTwoSym(TreeNode* one,TreeNode* two){
        if(one==nullptr||two==nullptr){
            return one==nullptr&&two==nullptr;
        }
        if(one->val!=two->val){
            return false;
        }
        return isTwoSym(one->left,two->right)&&isTwoSym(two->left,one->right);
    }
};
