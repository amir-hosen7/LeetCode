class Solution {
public:
    int dp[210][210];
    int solve(int row, int col, int n, vector<vector<int>>& v){
        if(row>=n or col>=n){
            return 0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int sum;
        if(row==0){
            sum=v[row][col]+solve(row+1, col, n, v);
        }
        else{
            int sum1=v[row][col]+solve(row+1, col, n, v);
            int sum2=INT_MAX;
            if((col+1)<n){
                sum2=v[row][col+1]+solve(row+1, col+1, n, v);
            }
            sum=min(sum1, sum2);
        }
        return dp[row][col]=sum;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        memset(dp, -1, sizeof(dp));
        return solve(0,0,n,triangle);
    }
};

