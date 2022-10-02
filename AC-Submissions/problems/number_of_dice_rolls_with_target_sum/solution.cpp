class Solution {
public:
    static const int mod=1e9+7;
    int dp[35][1010];
    int solve(int cnt, int n, int k, int target) {
        if(cnt==n) {
            if(target==0) return 1;
            return 0;
        }
        if(target<=0) return 0;
        int &ret=dp[cnt][target];
        if(ret!=-1) return ret;
        int ans=0;
        for(int i=1; i<=k and i<=target; i++) {
            ans=(ans+solve(cnt+1, n, k, target-i))%mod;
        }
        return ret=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(0, n, k, target);
    }
};