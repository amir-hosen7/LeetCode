class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v(2*n);
        int idx = 0;
        for (int i = 0, j = n; i < n; i++, j++) {
            v[idx++] = nums[i];
            v[idx++] = nums[j];
            }
        return v;
    }
};