class Solution {
public:
    int dp[100010][3][2];
    int solve(int idx, int currK, int n, int k, vector<int>& v, int status){
        if(idx>=n or currK>k){
            return 0;
        }
        if(dp[idx][currK][status]!=-1){
            return dp[idx][currK][status];
        }
        int profit;
        if(status){
            profit=max(v[idx]+solve(idx+1, currK, n, k, v, 0), solve(idx+1, currK, n, k, v, 1));
        }
        else{
            int profit1=solve(idx+1, currK+1, n, k, v, 1)-v[idx];
            int profit2=solve(idx+1, currK, n, k, v, 0);
            profit=max(profit1, profit2);
        }
        return dp[idx][currK][status]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), k=2;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, n, k, prices, 0);
    }
};