class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int>cnt(1010,0);
        for(int i=0; i<n; i++){
            int m=nums[i].size();
            for(int j=0; j<m; j++){
                cnt[nums[i][j]]++;
            }
        }
        vector<int>res;
        int m=nums[0].size();
        for(int i=0; i<m; i++){
            if(cnt[nums[0][i]]==n){
                res.push_back(nums[0][i]);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};