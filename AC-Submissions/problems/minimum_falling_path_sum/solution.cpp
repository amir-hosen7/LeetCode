class Solution {
public:
    int row, col, dp[110][110];
    int solve(int x, int y, vector<vector<int>>& mat) {
        if (x >= row or y < 0 or y >= col) {
            if (x == row) return 0;
            return 20000;
        }
        int &ret = dp[x][y];
        if (ret != -1) return ret;
        int ans1 = mat[x][y] + solve(x + 1, y, mat);
        int ans2 = mat[x][y] + solve(x + 1, y - 1, mat);
        int ans3 = mat[x][y] + solve(x + 1, y + 1, mat);
        int ans = min(ans1, min(ans2, ans3));
        return ret = ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        row = matrix.size(), col = matrix[0].size();
        int res = INT_MAX;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < col; i++) {
            //memset(dp, -1, sizeof(dp));
            res = min(res, solve(0, i, matrix));
        }
        return res;
    }
};