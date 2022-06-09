class Solution {
public:
    int dp[110][110];
    vector<int>cum;
    int solve(int idx, int n, int M){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][M]!=-1){
            return dp[idx][M];
        }
        int ans=0;
        for(int i=1; i<=(2*M) and (idx+i)<=n; i++){
            ans=max(ans, cum[idx]-solve(idx+i, n, max(M,i)));
        }
        return dp[idx][M]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        cum.resize(n+5, 0);
        cum[n-1]=piles[n-1];
        for(int i=n-1; i>=0; i--){
            cum[i]=cum[i+1]+piles[i];
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, n, 1);
    }
};