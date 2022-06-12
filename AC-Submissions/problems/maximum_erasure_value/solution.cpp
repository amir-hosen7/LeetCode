class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(),L=0;
        int res=0, sum=0;
        unordered_map<int,int>cnt;
        for(int i=0; i<n; i++){
            cnt[nums[i]]++;
            sum+=nums[i];
            while(cnt[nums[i]]>1){
                sum-=nums[L];
                cnt[nums[L++]]--;
            }
            res=max(res, sum);
        }
        return res;
    }
};