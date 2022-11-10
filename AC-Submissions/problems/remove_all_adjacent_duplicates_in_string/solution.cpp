class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        int len=s.size();
        for(int i=0; i<len; i++){
            if(res.size() and res.back()==s[i]){
                res.pop_back();
            }
            else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};