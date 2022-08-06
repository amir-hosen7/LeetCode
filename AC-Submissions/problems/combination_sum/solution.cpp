class Solution {
public:
    vector<int> curr;
    vector<vector<int>> ans;
    void solve(int idx, int n, int t, vector<int>& v) {
        if(idx>=n) {
            return;
        }
        if(t<=0) {
            if(t==0) {
                ans.push_back(curr);
            }
            return;
        }
        solve(idx+1, n, t, v);
        curr.push_back(v[idx]);
        solve(idx, n, t-v[idx], v);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        solve(0, n, target, candidates);
        return ans;
    }
};