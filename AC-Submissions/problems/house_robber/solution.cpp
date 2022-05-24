class Solution {
public:
    int dp[105],n;
    int solve(vector<int> &v, int idx){
        if(idx>=n){return 0;}
        if(dp[idx]!=-1){
            return dp[idx];
        }
       int a=v[idx]+solve(v,idx+2);
       int b=solve(v,idx+1);
       return dp[idx]=max(a,b);
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(nums,0);
        return ans;
    }
};