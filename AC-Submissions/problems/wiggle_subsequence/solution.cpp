class Solution {
public:
    int dp[1010][2];
    int solve(int idx, int n, int status, vector<int>& v){
        if(idx>=n){
            return 1;
        }
        if(dp[idx][status]!=-1){
            return dp[idx][status];
        }
        int ans=0;
        if(status){
            if(v[idx]<0){
                ans=1+solve(idx+1, n, 0, v);
            }
            else{
                ans=solve(idx+1, n, 1, v);
            }
        }
        else{
            if(v[idx]>0){
                ans=1+solve(idx+1, n, 1, v);
            }
            else{
                ans=solve(idx+1, n, 0, v);
            }
        }
        return dp[idx][status]=ans;
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<=n; i++){
            dp[i][0]=dp[i][1]=-1;
        }
        for(int i=0; i<(n-1); i++){
            nums[i]=nums[i+1]-nums[i];
        }
        return max(solve(0,n-1,0,nums), solve(0,n-1,1,nums));
    }
};