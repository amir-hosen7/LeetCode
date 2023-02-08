class Solution {
public:
    int dp[10010];
    int solve(int idx, int n, vector<int>& v) {
        if (idx == (n - 1)) return 0;
        int &ret = dp[idx];
        if (ret != -1) return ret;
        int ans = 1e9;
        for (int i = 1; (idx + i) < n and i <= v[idx]; i++) {
            ans = min(ans, 1 + solve(idx + i, n, v));
        }
        return ret = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, nums);
    }
};


