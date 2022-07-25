class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(), col=matrix[0].size();
        int L=0, R=(row*col)-1;
        while(L<=R){
            int mid=L+(R-L)/2;
            if(matrix[mid/col][mid%col]==target) return true;
            if(matrix[mid/col][mid%col]>target) R=mid-1;
            else L=mid+1;
        }
        return false;
    }
};


