class Solution {
public:
    long long dp[105][105];
    int row,col;
    long long solve(vector<vector<int>>&A, int m, int n){
         if(m==row and n==col){
              if(A[m-1][n-1]==1){return 0;}
              return 1;
         }
        if(m>row or n>col){return 0;}
        if(A[m-1][n-1]==1){return 0;}
        if(dp[m][n]!=-1){return dp[m][n];}
        return dp[m][n]=solve(A,m+1,n)+solve(A,m,n+1);
    }
    long long uniquePathsWithObstacles(vector<vector<int>>& obsta) {
        row=obsta.size(), col=obsta[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(obsta,1,1);
    }
};