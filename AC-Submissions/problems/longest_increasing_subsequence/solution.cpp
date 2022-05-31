class Solution {
public:
    int dp[2510];
    int lis(int idx, vector<int>& A, int n){
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans=0;
        for(int i=idx+1; i<n; i++){
            if(A[i]>A[idx]){
                ans=max(ans, lis(i,A,n));
            }
        }
        return dp[idx]=ans+1;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0; i<n; i++){
            ans=max(ans, lis(i,nums,n));
        }
        return ans;
    }
};