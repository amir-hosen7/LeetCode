class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n=s.size(), ok=0, ans=0;
        while(1){
            ok=0;
            for(int j=0; j<(n-1); j++){
                if(s[j]=='0' and s[j+1]=='1'){
                    ok=1;
                    swap(s[j], s[j+1]);
                    j++;
                }
            }
            if(ok) ans++;
            else break;
        }
        return ans;
    }
};