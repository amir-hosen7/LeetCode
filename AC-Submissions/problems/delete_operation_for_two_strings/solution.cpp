class Solution {
public:
    int dp[510][510], n, m;
    int solve(int i, int j, string& s, string& w){
        if(i==n){
            if(j==m){
                return 0;
            }
            return m-j;
        }
        if(j==m){
            if(i==n){
                return 0;
            }
            return n-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans;
        if(s[i]==w[j]){
            ans=solve(i+1, j+1, s, w);
        }
        else{
            int ans1=1+solve(i+1, j, s, w);
            int ans2=1+solve(i, j+1, s, w);
            ans=min(ans1, ans2);
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        n=word1.size(), m=word2.size();
        for(int i=0; i<510; i++){
            for(int j=0; j<510; j++){
                dp[i][j]=-1;
            }
        }
        return solve(0, 0, word1, word2);
    }
};


