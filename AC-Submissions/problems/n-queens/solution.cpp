class Solution {
public:
    int board[12];
    vector<vector<string>> res;

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
            string s;
            vector<string> v(n);
            for (int i = 1; i <= n; i++) s += '.';
            for (int i = 1; i <= n; i++) {
                string str = s;
                if (board[i]) {
                    str[i - 1] = 'Q';
                }
                v[board[i] - 1] = str;
            }
            res.push_back(v);
        }
        for (int i = 1; i <= n; i++) {
            if (isSafe(i, col)) {
                board[col] = i;
                NQueens(col + 1, n);
                board[col] = 0;
            }
        }
    } 

    vector<vector<string>> solveNQueens(int n) {
        NQueens(1, n);
        return res;
    }
};


