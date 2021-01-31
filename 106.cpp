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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //map<int,vector<int>::iterator>in_pos;
        //auto now = inorder.begin();
        //while(now!=inorder.end()){
        //    in_pos[*now]=now;
       //     now++;
       // }
        return doBuildTree(inorder,postorder,inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }
    TreeNode* doBuildTree(const vector<int>&inorder, const vector<int>&postorder,
                         vector<int>::iterator in_begin,vector<int>::iterator in_end,
                         vector<int>::iterator post_begin, vector<int>::iterator post_end
                          ){
        if(post_begin == post_end){
            return nullptr;
        }
        TreeNode *root = new TreeNode(*(post_end-1));
        //find root_node in inorder
        //auto in_root = in_pos[root->val];//O(logn) find;
        auto in_root = find(in_begin,in_end,root->val);
        //left_child_tree
        int left_tree_size = in_root - in_begin;
        auto post_left_begin = post_begin;
        auto post_left_end = post_left_begin + left_tree_size;
        auto in_left_begin = in_begin;
        auto in_left_end = in_root;
        root->left = doBuildTree(inorder,postorder,in_left_begin,in_left_end,post_left_begin,post_left_end);
        //right_child_tree
        auto post_right_begin = post_left_end;
        auto post_right_end = post_end-1;
        auto in_right_begin = in_root+1;
        auto in_right_end = in_end;
        root->right = doBuildTree(inorder,postorder,in_right_begin,in_right_end,post_right_begin,post_right_end);
        return root;
    }
};
