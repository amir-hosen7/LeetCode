class Solution {
public:
    int pascal[35][35];
    void solve(){
        for(int i=0; i<=33; i++){
            pascal[i][0]=pascal[i][i]=1;
            for(int j=1; j<i; j++){
                pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
            }
        }
    }
    vector<int> getRow(int rowIndex) {
        solve();
        vector<int>res;
        for(int i=0; i<=rowIndex; i++){
            res.push_back(pascal[rowIndex][i]);
        }
        return res;
    }
};