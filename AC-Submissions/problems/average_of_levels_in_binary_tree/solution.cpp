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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            double n=size(Q), tot=0;
            for(int i=1; i<=n; i++){
                TreeNode* u=Q.front();
                Q.pop();
                tot+=u->val;
                if(u->left) Q.push(u->left);
                if(u->right) Q.push(u->right);
            }
            res.push_back(tot/n);
        }
        return res;
    }
};











