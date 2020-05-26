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
    struct Node{
        Node(TreeNode* now){
            node = now;
            vr = false;
            vl = false;
        }
        TreeNode* node;
        bool vr;
        bool vl;
    };
    vector<int> postorderTraversal(TreeNode* root) {
        stack<Node> work;
        vector<int>output;
        if(root){
            work.push(Node(root));
        }
        while(!work.empty()){
            Node temp = work.top();
            if(temp.node->left&&!temp.vl){
                work.top().vl = true;
                work.push(Node(temp.node->left));
            }else if(temp.node->right&&!temp.vr){
                work.top().vr = true;
                work.push(temp.node->right);
                
            }else{
                output.push_back(temp.node->val);
                work.pop();
            }
        }
        return output;
    }
    
};

//not good enough, maybe.
//but it's simple enough.
