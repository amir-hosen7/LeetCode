class Solution {
public:
    int dp[100010];
    bool solve(int idx, int n, vector<int>& v){
        if(idx>=n) return 1;
        if(dp[idx]!=-1) return dp[idx];
        bool two=0;
        if(idx<(n-1)){
            if(v[idx]==v[idx+1]){
                two=solve(idx+2, n, v);
            }
        }
        bool three=0, consThree=0;
        if(idx<(n-2)){
            if(v[idx]==v[idx+1] and v[idx+1]==v[idx+2]){
                three=solve(idx+3, n, v);
            }
            if(v[idx]==v[idx+1]-1 and v[idx+1]==v[idx+2]-1){
                consThree=solve(idx+3, n, v);
            }
        }
        return dp[idx]=two|three|consThree;
    }
    
    bool validPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums.size(), nums);
    }
};

