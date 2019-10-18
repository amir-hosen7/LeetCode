class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = nums.size();
        vector <int> v; int flag = 0;
        for(int i = 0; i < l; i++){
            for(int j = i+1; j < l; j++){
                if(nums[j] == (target-nums[i])){
                    v.push_back(i); v.push_back(j);
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        return v;
    }
};