class Solution {
public:
    int dp[510][510];
    int solve(int i, int j, string &s, string &w){
        if(i==s.size()){
            if(j!=w.size()){
                return w.size()-j;
            }
            return 0;
        }
        if(j==w.size()){
            if(i!=s.size()){
                return s.size()-i;
            }
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans;
        if(s[i]==w[j]){
            ans=solve(i+1,j+1,s,w);
        }
        else{
            int remove=1+solve(i+1,j,s,w);
            int replace=1+solve(i+1,j+1,s,w);
            int insert=1+solve(i,j+1,s,w);
            ans=min(remove, min(replace, insert));
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, word1, word2);
    }
};