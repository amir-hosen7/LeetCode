class Solution {
public:
    int finalValueAfterOperations(vector<string>& s) {
        int n=s.size(), res=0;
        for(int i=0; i<n; i++){
            string curr=s[i];
            for(int j=0; j<3; j++){
                if(curr[j]=='+'){
                    res++; break;
                }
                if(curr[j]=='-'){
                    res--; break;
                }
            }
        }
        return res;
    }
};