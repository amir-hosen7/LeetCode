class Solution {
public:
    int findUnsortedSubarray(vector<int>& v) {
        int n=v.size(),start=-1,end,Max=-1000000;
        for(int i=0; i<(n-1); i++){
            Max=max(Max,v[i]);
            if(v[i]>v[i+1]){
                start=i; 
                break;
            }
        }
        if(start==-1){
            return 0;
        }
        for(int i=n-1; i>=1; i--){
            if(v[i]<v[i-1]){
                end=i;
                break;
            }
        }
        int Min=1000000;
        for(int i=start; i<=end; i++){
            Min=min(Min,v[i]);
            Max=max(Max,v[i]);
        }
        for(int i=0; i<start; i++){
            if(v[i]>Min){
                start=i; 
                break;
            }
        }
        for(int i=n-1; i>end; i--){
            if(v[i]<Max){
                end=i; break;
            }
        }
        return end-start+1;
    }
};