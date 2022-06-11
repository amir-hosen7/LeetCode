class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        string temp="!@#$%^&*()-+";
        unordered_map<char, bool>mark;
        int sz=temp.size();
        for(int i=0; i<sz; i++){
            mark[temp[i]]=1;
        }
        int n=s.size();
        for(int i=0; i<(n-1); i++){
            if(s[i]==s[i+1]){
                return false;
            }
        }
        bool up=0,low=0,sp=0,num=0;
        for(int i=0; i<n; i++){
            if(s[i]>='A' and s[i]<='Z'){
                up=1;
            }
            else if(s[i]>='a' and s[i]<='z'){
                low=1;
            }
            else if(s[i]>='0' and s[i]<='9'){
                num=1;
            }
            else if(mark[s[i]]==1){
                sp=1;
            }
        }
        return (up and low and num and sp and n>=8);
    }
};