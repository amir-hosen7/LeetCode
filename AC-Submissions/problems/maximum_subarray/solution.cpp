class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int n=v.size(),sum=0,Max=-1000000000;
        for(int i=0; i<n; i++){
            sum+=v[i];
            if(Max<sum){
                Max=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return Max;
    }
};