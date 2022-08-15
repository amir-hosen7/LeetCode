class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> Map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans=Map[s.back()], siz=s.size();
        for(int i=siz-2; i>=0; i--){
            if(Map[s[i]] < Map[s[i+1]]) ans-=Map[s[i]];
            else ans+=Map[s[i]];
        }
        return ans;
    }
};