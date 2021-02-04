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
    vector<vector<int>>output;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>nodes;
        nodes.push(root);
        doLevel(nodes);
        return output;
    }
    void doLevel(queue<TreeNode*>&pre){
        if(pre.empty()){
            return;
        }
        queue<TreeNode*>next;
        vector<int>thisLevel;
        while(!pre.empty()){
            if(pre.front()!=nullptr){
                next.push(pre.front()->left);
                next.push(pre.front()->right);
                thisLevel.push_back(pre.front()->val);
            }
            pre.pop();
        }
        doLevel(next);
        if(!thisLevel.empty())output.push_back(thisLevel);
    }
};
