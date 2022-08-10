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
    TreeNode* solve(int b, int e, vector<int>& nums) {
        int mid = b+(e-b)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        if((mid-1) >= b) {
            root->left = solve(b, mid-1, nums);
        }
        if((mid+1) <= e) {
            root->right = solve(mid+1, e, nums);
        }
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0, nums.size()-1, nums);
    }
};


