class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<=1){return n;}
        vector<int>res(n+5);
        res[0]=0, res[1]=1;
        int ans=0;
        for(int i=1; i<=(n-1)/2; i++){
            res[2*i]=res[i];
            res[2*i+1]=res[i]+res[i+1];
            ans=max(ans, max(res[i*2], res[i*2+1]));
        }
        if(n%2==0){
            ans=max(ans, res[n/2]);
        }
        return ans;
    }
};