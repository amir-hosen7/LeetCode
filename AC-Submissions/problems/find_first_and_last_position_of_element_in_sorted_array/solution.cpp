class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        vector<int> ans;
        if(lb == n or nums[lb] != target){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else{
            ans.push_back(lb);
            ans.push_back(ub-1);
        }
        return ans;
    }
};