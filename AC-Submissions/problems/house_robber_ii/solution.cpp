class Solution {
public:
    int dp[105][105],n;
    int solve(vector<int> &v, int idx, int cnt){
        if(idx>=n){return 0;}
        if(dp[idx][cnt]!=-1){
            return dp[idx][cnt];
        }
        int a=v[idx]+solve(v,idx+2,cnt+1);
        int b=solve(v,idx+1,cnt);
        return dp[idx][cnt]=max(a,b);
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        if(n==1){return nums[0];}
        memset(dp,-1,sizeof(dp));
        int a=solve(nums,1,1);
         memset(dp,-1,sizeof(dp));
        n--;
        int b=solve(nums,0,0);
        int ans=max(a,b);
        return ans;
    }
};