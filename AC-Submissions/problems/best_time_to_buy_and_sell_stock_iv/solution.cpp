class Solution {
public:
    int dp[1010][110][2];
    int solve(int idx, int n, int k, vector<int>& v, int status){
        if(idx>=n or k<=0) return 0;
        int &ret = dp[idx][k][status];
        if(ret!=-1) return ret;
        int ans=0;
        if(status){
            ans=max(v[idx] + solve(idx+1, n, k-1, v, 0), solve(idx+1, n, k, v, 1));
        }
        else{
            ans=max(solve(idx+1, n, k, v, 1) - v[idx], solve(idx+1, n, k, v, 0));
        }
        return ret=ans;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        int n=prices.size();
        return solve(0, n, k, prices, 0);
    }
};

