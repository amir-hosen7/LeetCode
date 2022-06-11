class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& M) {
        int n=s.size(), m=sub.size(), siz=M.size();
        map<pair<char, char>, bool>mark;
        for(int i=0; i<siz; i++){
            mark[{M[i][1], M[i][0]}]=1;
        }
        for(int i=0; i<n; i++){
            int idx=i, j=0;
            while(1){
                if(s[idx]!=sub[j]){
                    //cout<<s[idx]<<" "<<sub[j]<<"\n";
                    if(mark[{s[idx], sub[j]}]){
                        idx++, j++;
                    }
                    else{
                        break;
                    }
                }
                else{
                    idx++, j++;
                }
                if(j==m){
                    return true;
                }
            }
        }
        return false;
    }
};