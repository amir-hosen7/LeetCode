class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int n = nums.size(), OR = 0;
        for (int i = 0; i < n; i++) {
            OR = OR | nums[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int aa = nums[i] & OR;
            ans ^= aa;
        }
        return ans;
    }
};