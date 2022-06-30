class Solution {
public:
   
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mark;
        for(int i=0; i<n; i++){
            if(mark[nums[i]]){
                if((i-mark[nums[i]]+1)<=k){
                    return true;
                }
            }
            mark[nums[i]]=i+1;
        }
        return false;
    }
};


