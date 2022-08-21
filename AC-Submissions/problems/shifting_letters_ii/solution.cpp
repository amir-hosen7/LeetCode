class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=shifts.size(), siz=s.size();
        vector<int> optn(siz+5, 0);
        for(int i=0; i<n; i++){
            int L=shifts[i][0], R=shifts[i][1];
            int move=(shifts[i][2]==0)?-1:1;
            optn[L] += move, optn[R+1] -= move;
        }
        for(int i=0; i<siz; i++){
            if(i!=0) optn[i]+=optn[i-1];
            int idx=((s[i]-'a')+optn[i])%26;
            if(idx<0) idx+=26;
            s[i]=(char)idx+'a';
        }
        return s;
    }
};