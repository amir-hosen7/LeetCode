class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos,neg;
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        int idx=0, idx2=0;
        for(int i=0; i<n; i++){
            if(i%2==0){
                nums[i]=pos[idx++];
            }
            else{
                nums[i]=neg[idx2++];
            }
        }
        return nums;
    }
};


