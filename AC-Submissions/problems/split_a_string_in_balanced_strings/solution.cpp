class Solution {
public:
    int balancedStringSplit(string s) {
        int l = s.length(), L = 0, R = 0, cnt = 0;
        for(int j = 0; j < l; j++){
            if(s[j] == 'R'){
                R++;
            }
            else{
                L++;
            }
            if(L == R){
                cnt++; L = 0; R = 0;
            }
        }
        return cnt;
    }
};