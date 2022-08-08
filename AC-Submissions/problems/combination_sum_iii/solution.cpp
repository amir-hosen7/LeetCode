class Solution {
public:
    vector<int>curr;
    vector<vector<int>>ans;
    void solve(int idx, int take, int k, int t){
        if(take>k) return;
        if(t<=0){
            if(t==0 and take==k) ans.push_back(curr);
            return;
        }
        for(int i=idx+1; i<=9; i++){
            curr.push_back(i);
            solve(i, take+1, k, t-i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(0, 0, k, n);
        return ans;
    }
};