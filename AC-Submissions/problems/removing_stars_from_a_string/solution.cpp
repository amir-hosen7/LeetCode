class Solution {
public:
    string removeStars(string s) {
        int n=s.size(), star=0;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='*'){
                star++;
            }
            else{
                bool ok=0;
                while(star>0 and s[i]!='*'){
                    ok=1;
                    s[i]='*';
                    i--, star--;
                }
                if(ok) i++;
            }
        }
        string ans;
        for(int i=0; i<n; i++){
            if(s[i]!='*') ans+=s[i];
        }
        return ans;
    }
};