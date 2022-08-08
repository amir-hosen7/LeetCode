class Solution {
public:
    vector<int> curr;
    vector<vector<int>> ans;
    void solve(int idx, int n, int t, vector<int>& v) {
        if(t<=0) {
            if(t==0) {
                ans.push_back(curr);
            }
            return;
        }
        for(int i=idx; i<n; i++) {
            curr.push_back(v[i]);
            solve(i, n, t-v[i], v);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        solve(0, n, target, candidates);
        return ans;
    }
};

