class Solution{
public:
    int coinChange(vector<int>& coins, int amount){
    	int len=coins.size();
        int dp[len+5][amount+5];
        for(int i=0; i<=len; i++){
            for(int j=0; j<=amount; j++){
                dp[i][j]=100000;
            }
        }
        for(int i=0; i<len; i++){
        	dp[i][0]=0;
        }
        for(int i=0; i<len; i++){
        	for(int j=1; j<=amount; j++){
        		if(j>=coins[i]){
        			if(i>0){
        				dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i]]+1);
        			}
        			else{
        				dp[i][j]=min(100000,dp[i][j-coins[i]]+1);
        			}
        		}
        		else{
        			if(i>0){
        				dp[i][j]=dp[i-1][j];
        			}
        		}
        	}
        }
        if(dp[len-1][amount]==100000){
        	return -1;
        }
        else{
        	return dp[len-1][amount];
        }
    }
};