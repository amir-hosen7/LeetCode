class Solution {
public:
    int dp[1010][1010];
    
    int solve(int i, int j, string &s, string &w){
        if(i==s.size() or j==w.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans;
        if(s[i]==w[j]){
            ans=1+solve(i+1,j+1,s,w);
        }
        else{
            ans=max(solve(i+1,j,s,w), solve(i,j+1,s,w));
        }
        return dp[i][j]=ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,text1,text2);
    }
};