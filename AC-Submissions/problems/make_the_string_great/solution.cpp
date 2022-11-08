class Solution {
public:
    string makeGood(string s) {
        int siz=s.size();
        string res;
        for(int i=0; i<siz; i++){
            res.push_back(s[i]);
            while(res.size() and abs(s[i+1]-res.back())==32){
                res.pop_back(), i++;
            }
        }
        return res;
    }
};