class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        int n=nums.size();
        unordered_map<int, int>idx;
        for(int i=0; i<n; i++){
            idx[nums[i]]=i;
        }
        for(int i=0; i<n; i++){
            int currVal=target-nums[i];
            if(idx[currVal]>i){
                res.push_back(i);
                res.push_back(idx[currVal]);
                break;
            }
        }
        return res;
    }
};