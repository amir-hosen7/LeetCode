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
    struct Data{
        TreeNode *parent, *grandparent;
    };
    
    int sumEvenGrandparent(TreeNode* root) {
        int L=0, R=0, ans=0;
        Data Q[10010];
        Q[R++]={root, NULL};
        while(L<R){
            TreeNode* curr_parent=Q[L].parent;
            TreeNode* curr_grand=Q[L].grandparent;
            if(curr_parent->left){
                if(curr_grand and curr_grand->val%2==0){
                    ans+=(curr_parent->left->val);
                }
                Q[R++]={curr_parent->left, curr_parent};
            }
            if(curr_parent->right){
                if(curr_grand and curr_grand->val%2==0){
                    ans+=(curr_parent->right->val);
                }
                Q[R++]={curr_parent->right, curr_parent};
            }
            L++;
        }
        return ans;
    }
};




