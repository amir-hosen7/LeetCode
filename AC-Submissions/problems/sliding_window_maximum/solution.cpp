class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int logn[n+5];
        logn[1]=0;
        for(int i=2; i<=n; i++){
            logn[i]=logn[i/2]+1;
        }
        int table[32][n+5];
        for(int i=0; i<=logn[n]; i++){
            int curr_len=1<<i;
            for(int j=0; (j+curr_len)<=n; j++){
                if(curr_len==1){
                    table[i][j]=nums[j];
                }
                else{
                    table[i][j]=max(table[i-1][j], table[i-1][j+(curr_len/2)]);
                }
            }
        }
        vector<int>ans;
        for(int i=0; i<=(n-k); i++){
            int L=i,R=i+(k-1);
            int p=logn[R-L+1];
            int len=1<<p;
            int res=max(table[p][L],table[p][R-len+1]);
            ans.push_back(res);
        }
        return ans;
    }
};