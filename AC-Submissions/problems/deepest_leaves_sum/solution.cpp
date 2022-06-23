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
    int getDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int L=0, R=0;
        if(root->left){
            L=1+getDepth(root->left);
        }
        if(root->right){
            R=1+getDepth(root->right);
        }
        return max(L, R);
    }
    
    struct data{
        TreeNode* node;
        int dist;
    };
    
    int solve(TreeNode* root, int maxDepth){
        data Q[100000];
        int L=0, R=0, ans=0;
        Q[R++]={root, 0};
        while(L<R){
            TreeNode* curr=Q[L].node;
            int depth=Q[L].dist;
            if(depth==maxDepth){
                ans+=curr->val;
            }
            if(curr->left){
                Q[R++]={curr->left, depth+1};
            }
            if(curr->right){
                Q[R++]={curr->right, depth+1};
            }
            L++;
        }
        return ans;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth=getDepth(root);
        return solve(root, maxDepth);
    }
};

