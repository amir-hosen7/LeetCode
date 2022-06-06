class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>cnt(110,0), cum(110);
        for(auto i:nums){
            cnt[i]++;
        }
        cum[0]=0;
        for(int i=0; i<=100; i++){
            if(i==0){
                cum[i]=cnt[i];
            }
            else{
                cum[i]=cnt[i]+cum[i-1];
            }
        }
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                 nums[i]=cum[nums[i]-1];
            }
        }
        return nums;
    }
};