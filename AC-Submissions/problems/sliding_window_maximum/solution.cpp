class Solution {
public:
    int table[22][100050],logs[100050];
    void build(vector<int>&v, int n){
        logs[1]=0;
        for(int i=2; i<=n; i++){
            logs[i]=logs[i/2]+1;
        }
        for(int i=0; i<=logs[n]; i++){
            int currLen=1<<i;
            for(int j=0; (j+currLen)<=n; j++){
                if(currLen==1){
                    table[i][j]=v[j];
                }
                else{
                    table[i][j]=max(table[i-1][j],table[i-1][j+currLen/2]);
                }
            }
        }
    }
    
    int getMax(int L, int R){
        int p=logs[R-L+1];
        int pLen=1<<p;
        return max(table[p][L],table[p][R-pLen+1]);
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        build(nums,n);
        vector<int>res;
        for(int i=0; i<=(n-k); i++){
            res.push_back(getMax(i,i+k-1));
        }
        return res;
    }
};