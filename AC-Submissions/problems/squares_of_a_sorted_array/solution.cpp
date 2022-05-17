class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int Min=100000,n=nums.size(),idx;
        for(int i=0; i<n; i++){
        	nums[i]=abs(nums[i]);
        	if(nums[i]<Min){
        		Min=nums[i];
        		idx=i;
        	}
        }

        vector<int>res(n);
        res[0]=Min*Min;
        int L=idx-1,R=idx+1;
        idx=1;
        while(L>=0 and R<n){
        	if(nums[L]<nums[R]){
        		res[idx++]=nums[L]*nums[L];
        		L--;
        	}
        	else{
        		res[idx++]=nums[R]*nums[R];
        		R++;
        	}
        }
        while(L>=0){
        	res[idx++]=nums[L]*nums[L];
        	L--;
        }
        while(R<n){
        	res[idx++]=nums[R]*nums[R];
        	R++;
        }
        return res;
    }
};