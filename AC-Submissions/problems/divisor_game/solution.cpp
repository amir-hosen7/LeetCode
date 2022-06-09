class Solution {
public:
   
    // bool divisorGame(int n) {
    //     bool dp[n+5];
    //     dp[1]=false, dp[2]=true;
    //     for(int i=3; i<=n; i++){
    //         dp[i]=!dp[i-1];
    //     }
    //     return dp[n];
    // }
    
     bool divisorGame(int n) {
        return (n%2==0)?true:false;
    }
};