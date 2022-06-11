class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long cnt=0, sum=0,L=0,res=0;
        for(int i=0; i<n; i++){
            cnt++, sum+=nums[i];
            long long aa=cnt*sum;
            bool ok=0;
            while(k<=aa){
                cnt--;
                sum-=nums[L++];
                aa=cnt*sum;
                if(aa<k){
                    res+=cnt;
                    ok=1;
                }
            }
            if(!ok and aa<k){
                res+=cnt;
            }
        }
        return res;
    }
};