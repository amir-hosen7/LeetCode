class Solution {
public:
    vector<int> curr;
    vector<vector<int>> ans;
    void solve(int idx, int n, vector<int>& v, int t){
        if(t<=0){
            if(t==0){
                ans.push_back(curr);
            }
            return;
        }
        for(int i=idx+1; i<n; i++){
            curr.push_back(v[i]);
            solve(i, n, v, t-v[i]);
            curr.pop_back();
            while((i+1)<n and (v[i]==v[i+1])){
                i++;
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(), candidates.end());
        solve(-1, n, candidates, target);
        return ans;
    }
};


