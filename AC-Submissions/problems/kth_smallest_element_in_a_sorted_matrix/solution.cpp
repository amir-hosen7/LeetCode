class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>A;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                A.push_back(matrix[i][j]);
            }
        }
        sort(A.begin(), A.end());
        return A[k-1];
    }
};