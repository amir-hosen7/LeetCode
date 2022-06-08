class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int pascal[numRows][numRows];
        for(int i=0; i<numRows; i++){
            pascal[i][0]=pascal[i][i]=1;
            for(int j=1; j<i; j++){
                pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
            }
        }
        vector<vector<int>>res;
        for(int i=0; i<numRows; i++){
            vector<int>v;
            for(int j=0; j<=i; j++){
                v.push_back(pascal[i][j]);
            }
            res.push_back(v);
        }
        return res;
    }
};