class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int>A(n), B(n);
        for(int i=0; i<n; i++){
            if(i==0){
                A[i]=nums[i];
            }
            else{
                A[i]=A[i-1] + nums[i];
            }
        }
        reverse(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(i==0){
                B[i]=nums[i];
            }
            else{
                B[i]=B[i-1] + nums[i];
            }
        }
        int idx=upper_bound(B.begin(), B.end(), x) - B.begin();
        //cout<<idx<<" idx\n";
        idx--;
        if(idx>=0){
            
        }
        int res=INT_MAX;
        if(idx>=0){
            if(B[idx]==x){
                res=idx+1;
            }
        }
        
        //cout<<res<<"\n";
        for(int i=0; i<n; i++){
            if(A[i]>x){
                break;
            }
            int temp=x-A[i];
            if(temp==0){
                res=min(res, i+1);
            }
            else{
                idx=upper_bound(B.begin(), B.end(), temp) - B.begin();
                //cout<<i<<" "<<idx<<" idx inside\n";
                idx--;
                if(idx>=0){
                    if(B[idx]==temp and (i+idx+2)<=n){
                        //cout<<i<<" "<<idx<<"\n";
                        res=min(res, i+1+idx+1);
                    }
                }
            }
        }
        return (res==INT_MAX)?-1:res;
    }
};

