class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>A(n,1),B(n,1);
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                A[i]=A[i-1]+1;
            }
        }
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                B[i]=B[i+1]+1;
            }
        }
        int res=0;
        for(int i=0; i<n; i++){
            res+=max(A[i], B[i]);
        }
        return res;
    }
};

