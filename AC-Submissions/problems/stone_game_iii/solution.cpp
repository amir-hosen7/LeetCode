class Solution {
public:
    vector<int>cum;
    int dp[50010];
    int solve(int idx, int n){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans=INT_MIN;
        for(int i=1; i<=3 and (idx+i)<=n; i++){
            ans=max(ans, cum[idx]-solve(idx+i, n));
        }
        return dp[idx]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        cum.resize(n+10, 0);
        cum[n-1]=stoneValue[n-1];
        for(int i=n-2; i>=0; i--){
            cum[i]=cum[i+1]+stoneValue[i];
        }
        memset(dp, -1, sizeof(dp));
        int sum=solve(0, n);
        //cout<<sum<<" "<<cum[0]<<"\n";
        if(sum>(cum[0]-sum)){
            return "Alice";
        }
        else if(sum<(cum[0]-sum)){
            return "Bob";
        }
        else{
            return "Tie";
        }
    }
};