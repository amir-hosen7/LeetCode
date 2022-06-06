/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==target or cloned==NULL){
            return cloned;
        }
        TreeNode* A=getTargetCopy(original->left, cloned->left, target);
        TreeNode* B=getTargetCopy(original->right, cloned->right, target);
        if(A==NULL){
            return B;
        }
        else{
            return A;
        }
        if(B==NULL){
            return A;
        }
        else{
            return B;
        }
    }
};