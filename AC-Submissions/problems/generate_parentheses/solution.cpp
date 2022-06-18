class Solution {
public:
    vector<string>res;
    void solve(int L, int R, int n, string s){
        if(L==n and R==n){
            res.push_back(s);
            return;
        }
        if(L<n){
            solve(L+1, R, n, s+'(');
        }
        if(L>R){
            solve(L, R+1, n, s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        solve(0,0,n,s);
        return res;
    }
};

