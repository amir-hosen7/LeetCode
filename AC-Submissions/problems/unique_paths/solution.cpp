class Solution {
public:
    long long dp[105][105];
    int row,col;
    long long solve(int m, int n){
        if(m==row and col==n){
            return 1;
        }
        if(m>row or n>col){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        long long a=solve(m+1,n);
        long long b=solve(m,n+1);
        return dp[m][n]=a+b;
    }
    long long uniquePaths(int m, int n) {
        row=m, col=n;
        memset(dp,-1,sizeof(dp));
        return solve(1,1);
    }
};