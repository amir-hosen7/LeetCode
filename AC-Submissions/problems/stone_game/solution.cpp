class Solution {
public:
    int dp[510][510][2];
    int solve(int L, int R, int n, vector<int>& v, int status){
        if(L==n or R<0 or L>R){
            return 0;
        }
        if(dp[L][R][status]!=-1){
            return dp[L][R][status];
        }
        int ans=0;
        if(!status){
            int alice1=v[L]+solve(L+1, R, n, v, 1);
            int alice2=v[R]+solve(L, R-1, n, v, 1);
            ans=max(alice1, alice2);
        }
        else{
            int alice1=solve(L+1, R, n, v, 0);
            int alice2=solve(L, R-1, n, v, 0);
            ans=max(alice1, alice2);
        }
        return dp[L][R][status]=ans;
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size(),sum=0;
        for(int i=0; i<n; i++){
            sum+=piles[i];
        }
        memset(dp, -1, sizeof(dp));
        int ans=solve(0,n-1,n,piles,0);
        return (ans>(sum-ans))?true:false;
    }
};

