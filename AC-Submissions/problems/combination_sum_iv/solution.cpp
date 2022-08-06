class Solution {
public:
    int dp[1010], siz;
    int solve(int n, vector<int>& v) {
        if(n<=0) {
            return (n==0)? 1:0;
        }
        if(dp[n]!=-1) return dp[n];
        int ans=0;
        for(int i=0; i<siz; i++) {
            ans+=solve(n-v[i], v);
        }
        return dp[n]=ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        siz=nums.size();
        for(int i=0; i<=1005; i++) dp[i]=-1;
        return solve(target, nums);
    }
};


