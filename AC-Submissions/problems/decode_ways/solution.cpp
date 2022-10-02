class Solution {
public:
    int dp[110];
    int solve(int idx, int n, string &s) {
        if(idx>=n) return 1;
        int &ret = dp[idx];
        if(ret!=-1) return ret;
        int ans=0;
        if(idx<=(n-2) and s[idx]!='0'){
            if(s[idx]<='2' and (s[idx+1]<='6' or s[idx]=='1')){
                ans=solve(idx+1, n, s)+solve(idx+2, n, s);
            }
            else{
                ans=solve(idx+1, n, s);
            }
        }
        else if(s[idx]!='0'){
            ans=solve(idx+1, n, s);
        }
        return ret = ans;
    }
    
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        memset(dp, -1, sizeof(dp));
        return solve(0, s.size(), s);
    }
};


