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
    vector<int> res;
    void solve(TreeNode* root){
        if(root==NULL) return;
        if(root->left){
            solve(root->left);
        }
        res.push_back(root->val);
        if(root->right){
            solve(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return res;
    }
};


