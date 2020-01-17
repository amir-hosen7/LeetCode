class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>ans;
        int vl = nums.size();
        for(int i=0; i<vl-1; i+=2){
            int a = nums[i];
            int b = nums[i+1];
            for(int j=0; j<a; j++){
                ans.push_back(b);
            }
        }
        return ans;
    }
};