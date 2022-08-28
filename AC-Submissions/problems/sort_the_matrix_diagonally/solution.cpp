class Solution {
public:
    void solve(int x, int y, int row, int col, vector<vector<int>>& mat){
        while(x<col and y<row){
            int a=x+1, b=y+1, curr=mat[y][x], X=x, Y=y;
            while(a<col and b<row){
                if(mat[b][a]<curr){
                    curr=mat[b][a], X=a, Y=b;
                }
                //cout<<a<<" "<<b<<" ab\n";
                a++, b++;
            }
            swap(mat[y][x], mat[Y][X]);
            //cout<<x<<" "<<y<<" xy\n";
            x++, y++;
        }
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row=mat.size(), col=mat[0].size();
        for(int i=1; i<col; i++){
            solve(i, 0, row, col, mat);
        }
        for(int i=0; i<row; i++){
            solve(0, i, row, col, mat);
        }
        return mat;
    }
};

