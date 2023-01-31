class Solution {
public:
    int dp[1010][1010];
    int solve(int idx, int n, int curr, vector<pair<int, int>>& v) {
        if (idx >= n) return 0;
        int &ret = dp[idx][curr];
        if (ret != -1) return ret;
        int ans1 = 0;
        if (v[idx].second <= curr) {
           ans1 = v[idx].first + solve(idx + 1, n, v[idx].second, v);
        }
        int ans2 = solve(idx + 1, n, curr, v);
        return ret = max(ans1, ans2);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({scores[i], ages[i]});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        memset(dp, -1, sizeof(dp));
        int res = solve(0, n, 1005, v);
        return res;
    }
};



