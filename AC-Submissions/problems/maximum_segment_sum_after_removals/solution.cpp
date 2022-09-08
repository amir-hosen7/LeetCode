class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n=nums.size();
        vector<long long> cum(n+1), res;
        cum[0]=0;
        for(int i=1; i<=n; i++){
            cum[i]=cum[i-1]+nums[i-1];
        }
        for(int i=0; i<n; i++){
            nums[i]=-1;
        }
        long long currMax=0;
        for(int i=n-1; i>=0; i--){
            int q=removeQueries[i];
            res.push_back(currMax);
            if(q==0){
                if(n>1 and nums[q+1]!=-1){
                    int R=nums[q+1];
                    long long segSum=cum[R+1];
                    currMax=max(currMax, segSum);
                    nums[R]=q;
                    nums[q]=R;
                }
                else{
                    currMax=max(currMax, cum[1]);
                    nums[q]=q;
                }
            }
            else if(q==(n-1)){
                if(n>1 and nums[q-1]!=-1){
                    int L=nums[q-1];
                    long long segSum=cum[n]-cum[L];
                    currMax=max(currMax, segSum);
                    nums[L]=q;
                    nums[q]=L;
                }
                else{
                    currMax=max(currMax, cum[n]-cum[n-1]);
                    nums[q]=q;
                }
            }
            else{
                if(nums[q-1]!=-1 and nums[q+1]!=-1){
                    int L=nums[q-1], R=nums[q+1];
                    long long segSum=cum[R+1]-cum[L];
                    currMax=max(currMax, segSum);
                    nums[R]=L;
                    nums[L]=R;
                }
                else if(nums[q-1]!=-1){
                    int L=nums[q-1];
                    long long segSum=cum[q+1]-cum[L];
                    currMax=max(currMax, segSum);
                    nums[L]=q;
                    nums[q]=L;
                }
                else if(nums[q+1]!=-1){
                    int R=nums[q+1];
                    long long segSum=cum[R+1]-cum[q];
                    currMax=max(currMax, segSum);
                    nums[R]=q;
                    nums[q]=R;
                }
                else{
                    currMax=max(currMax, cum[q+1]-cum[q]);
                    nums[q]=q;
                }
            }
            //cout<<q<<" "<<currMax<<"\n";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};



