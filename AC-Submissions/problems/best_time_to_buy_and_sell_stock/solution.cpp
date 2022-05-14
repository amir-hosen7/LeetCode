class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size(),Min=1e9,Max=0;
        vector<int>right(n),left(n);
        for(int i=0; i<n; i++){
        	Min=min(Min,nums[i]);
        	right[i]=Min;
        }
        for(int i=n-1; i>=0; i--){
        	Max=max(Max,nums[i]);
        	left[i]=Max;
        }
        int res=0;
        for(int i=0; i<n; i++){
        	if(right[i]<left[i]){
        		res=max(res,left[i]-right[i]);
        	}
        }
        return res;
    }
};