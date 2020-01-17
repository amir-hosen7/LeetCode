class Solution {
public:
    string longestPalindrome(string s) {
        string T;
        T += "$"; int sl = s.length();
        for(int i=0; i<sl; i++){
            T += "#"; T += s[i];
        }
        T += "#@";
        vector<int>P(T.length(),0);
        int center = 0, right = 0;
        int tl = T.length();
        for(int i=1; i<tl-1; i++){
            int mir = 2*center - i;
            if(i<right){
                P[i] = min(right-i, P[mir]);
            }
            while(T[i+(1+P[i])] == T[i-(1+P[i])]){
                P[i]++;
            }
            if((i+P[i])>right){
                center = i; right = i+P[i];
            }
        }
        int mxLen = 0; center = 0;
        for(int i=1; i<tl-1; i++){
            if(mxLen<P[i]){
                mxLen = P[i]; center = i;
            }
        }
        int left = (center-mxLen-1)/2; right = (center+mxLen-1)/2-1;
        string ans;
        for(int i=left; i<=right; i++){
            ans+=s[i];
        }
        return ans;
    }
};