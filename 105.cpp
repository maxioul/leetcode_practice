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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return doBuildTree(preorder,inorder,preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
    
    TreeNode* doBuildTree(const vector<int>& preorder, const vector<int>& inorder,
                          vector<int>::iterator pre_begin,vector<int>::iterator pre_end,
                         vector<int>::iterator in_begin, vector<int>::iterator in_end){
        if(pre_begin == pre_end){
            return nullptr;
        }
        TreeNode *root = new TreeNode(*pre_begin);
        //find root_node in inoder
        auto in_root = find(in_begin,in_end,*pre_begin);//O(n)find, can imporve by map<int, vector<int>::iterator>inorder_position;
        //left_childtree
        int left_tree_size = in_root - in_begin;
        auto pre_left_begin = pre_begin+1;
        auto pre_left_end = pre_left_begin + left_tree_size;
        auto in_left_begin = in_begin;
        auto in_left_end = in_root;
        root->left = doBuildTree(preorder, inorder, pre_left_begin,pre_left_end,in_left_begin,in_left_end);
        //right_childtree
        auto pre_right_begin = pre_left_end;
        auto pre_right_end = pre_end;
        auto in_right_begin = in_root+1;
        auto in_right_end = in_end;
        root->right = doBuildTree(preorder, inorder,pre_right_begin,pre_right_end,in_right_begin,in_right_end);
        return root;
    }
};
