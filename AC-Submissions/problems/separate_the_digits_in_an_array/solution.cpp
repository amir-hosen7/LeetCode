class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            while (nums[i]) {
                temp.push_back(nums[i] % 10);
                nums[i] /= 10;
            }
            for (int j = temp.size() - 1; j >= 0; j--) {
                res.push_back(temp[j]);
            }
        }
        return res;
    }
};