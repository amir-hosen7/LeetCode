class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int siz=nums.size(),mex=1;
        vector<bool>mark(siz+5,false);
        for(int i=0; i<siz; i++){
            if(nums[i]<=siz and nums[i]>0){
                mark[nums[i]]=true;
                if(nums[i]==mex){
                    while(mark[mex]==true){
                        mex++;
                    }
                }
            }
        }
        return mex;
    }
};