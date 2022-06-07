class Solution {
public:
    vector<string>res;
    unordered_map<char, string>Map={{'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9', "wxyz"}};
    void solve(int idx, string s, string ans){
        if(idx==s.size()){
            if(ans.size()==s.size() and s.size()>0){
                 res.push_back(ans);
            }
            return;
        }
        for(int i=idx; i<s.size(); i++){
            string temp=Map[s[i]];
            for(auto j:temp){
                solve(i+1, s, ans+j);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        string s;
        solve(0, digits, s);
        return res;
    }
};