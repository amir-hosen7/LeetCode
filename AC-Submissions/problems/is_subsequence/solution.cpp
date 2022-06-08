class Solution {
public:
    
    bool isSubsequence(string s, string t) {
        if(s==t){return true;}
        if(s.size()>t.size()){
            return false;
        }
        int sl=s.size(), tl=t.size(),idx=0;
        for(int i=0; i<tl; i++){
            if(s[idx]==t[i]){
                idx++;
            }
            if(idx==sl){
                return true;
            }
        }
        return false;
    }
};