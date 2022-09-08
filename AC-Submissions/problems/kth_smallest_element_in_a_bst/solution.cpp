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
    int res, cnt;
    void solve(TreeNode* root){
        if(root==NULL) return;
        if(root->left) solve(root->left);
        if(cnt>=0){
            cnt--;
            if(cnt==0) res=root->val;
        }
        if(root->right) solve(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        cnt=k;
        solve(root);
        return res;
    }
};