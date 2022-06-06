class Solution {
public:
    string defangIPaddr(string s) {
        int n=s.size();
        string res;
        for(int i=0; i<n; i++){
            if(s[i]=='.'){
                res+="[.]";
            }
            else{
                res+=s[i];
            }
        }
        return res;
    }
};