class Solution {
public:
    int dp[1010][1010];
    int solve(int i, int j, string &s, string &w){
        if(i==s.size()){
            int sum=0;
            while(j!=w.size()){
                sum+=(int)w[j++];
            }
            return sum;
        }
        if(j==w.size()){
            int sum=0;
            while(i!=s.size()){
                sum+=(int)s[i++];
            }
            return sum;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans;
        if(s[i]==w[j]){
            ans=solve(i+1,j+1,s,w);
        }
        else{
            int aa=(int)s[i]+solve(i+1,j,s,w);
            int bb=(int)w[j]+solve(i,j+1,s,w);
            ans=min(aa,bb);
        }
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s1,s2);
    }
};