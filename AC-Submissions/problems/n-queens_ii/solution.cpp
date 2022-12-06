class Solution {
public:
    int board[12], res;

    bool isSafe(int row, int col) {
        for (int i = 1; i <= col; i++) {
            if (board[i] == row) return false;
            int x = abs(row - board[i]), y = col - i;
            if (x == y) return false;
        }
        return true;
    }

    void NQueens(int col, int n) {
        if (col > n){
            res++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (isSafe(i, col)) {
                board[col] = i;
                NQueens(col + 1, n);
                board[col] = 0;
            }
        }
    } 
    int totalNQueens(int n) {
        NQueens(1, n);
        return res;
    }
};


