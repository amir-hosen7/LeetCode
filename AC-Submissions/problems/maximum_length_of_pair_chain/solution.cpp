class Solution {
public:
    int dp[1010];
    int lis(int idx, vector<pair<int,int>>& A, int n){
        if(dp[idx]!=-1){return dp[idx];}
        int ans=0;
        for(int i=idx+1; i<n; i++){
            if(A[i].first>A[idx].second){
                ans=max(ans, lis(i,A,n));
            }
        }
        return dp[idx]=ans+1;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<pair<int,int>>A(n);
        for(int i=0; i<n; i++){
            A[i]={pairs[i][0],pairs[i][1]};
        }
        sort(A.begin(),A.end());
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<n; i++){
            ans=max(ans, lis(i,A,n));
        }
        return ans;
    }
};