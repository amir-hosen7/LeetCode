class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int A1=INT_MAX, A2=INT_MAX;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(A1>nums[i]){
                A1=nums[i];
            }
            if(nums[i]<A2){
                if(nums[i]>A1){
                    A2=nums[i];
                }
            }
            if(nums[i]>A2){
                return true;
            }
        }
        return false;
    }
};