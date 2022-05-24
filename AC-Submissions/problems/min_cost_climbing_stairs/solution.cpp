class Solution {
public:
    int n,dp[1005];
    int solve(vector<int>&cost, int idx){
        if(idx>=n){return 0;}
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int a=cost[idx]+solve(cost,idx+1);
        int b=cost[idx]+solve(cost,idx+2);
        return dp[idx]=min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(cost,0);
        memset(dp,-1,sizeof(dp));
        ans=min(ans,solve(cost,1));
        return ans;
    }
};