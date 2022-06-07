class Solution {
public:
    int dp[210][210], row, col;
    int solve(int x, int y, vector<vector<int>>&grid){
         if(x>=row or y>=col){
            return 1e5;
        }
        if(x==row-1 and y==col-1){
            return grid[x][y];
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int ans1=grid[x][y]+solve(x, y+1, grid);
        int ans2=grid[x][y]+solve(x+1, y, grid);
        return dp[x][y]=min(ans1, ans2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        row=grid.size(), col=grid[0].size();
        return solve(0,0,grid);
    }
};