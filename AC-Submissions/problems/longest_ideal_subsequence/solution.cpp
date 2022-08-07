class Solution {
public:
    int dp[100010][30];
    int solve(int idx, int curr, int n, string &s, int k){
        if(idx >= n) return 0;
        if(dp[idx][curr]!=-1) return dp[idx][curr];
        int id=s[idx]-'a'+1, ans;
        if(abs(id-curr)<=k) {
            int ans1=solve(idx+1, id, n, s, k)+1;
            int ans2=solve(idx+1, curr, n, s, k);
            ans=max(ans1, ans2);
        }
        else{
            ans=solve(idx+1, curr, n, s, k);
        }
        return dp[idx][curr]=ans;
    }
    int longestIdealString(string s, int k) {
        memset(dp, -1, sizeof(dp));
        int ans=0, n=s.size();
        for(int i=0; i<n; i++){
            ans=max(ans, solve(0, s[i]-'a'+1, n, s, k));
        }
        return ans;
    }
};