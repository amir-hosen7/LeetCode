class Solution {
public:
    int dp[1010][1010];
    int solve(int L, int R, string &s){
        if(L>=R){
            return (L==R)?1:0;
        }
        int &ret=dp[L][R];
        if(ret!=-1){
            return ret;
        }
        int ans;
        if(s[L]==s[R]){
            ans=2+solve(L+1, R-1, s);
        }
        else{
            ans=max(solve(L+1, R, s), solve(L, R-1, s));
        }
        return ret=ans;
    }
    int longestPalindromeSubseq(string s){
        memset(dp, -1, sizeof(dp));
        return solve(0,s.size()-1,s);
    }
};


