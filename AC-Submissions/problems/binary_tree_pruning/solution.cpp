//Will solve

class Solution {
public:
    int help(TreeNode* root)
    {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL)
        {
            return root->val;
        }
        int a=help(root->left);
        int b=help(root->right);
        if(a==0) root->left=NULL;
        if(b==0) root->right=NULL;
        return (a+b+root->val);
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        int a=help(root);
        if(a==0)return NULL;
        return root;
        
    }
};