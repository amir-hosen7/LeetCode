class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = s.size(), cnt = 0;
        string curr = "", str = "";
        unordered_map<char, bool> vis;
        unordered_map<string, char> mark;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (mark[curr] > 'z' or mark[curr] < 'a'){
                    if (vis[pattern[cnt]] == 0) mark[curr] = pattern[cnt];
                    else mark[curr] = '0';
                    vis[pattern[cnt]] = 1;
                }
                str += mark[curr];
                cnt++, curr = "";
            }
            else{
                curr += s[i];
            }
        }
        if (mark[curr] > 'z' or mark[curr] < 'a'){
            if (vis[pattern[cnt]] == 0) mark[curr] = pattern[cnt];
            else mark[curr] = '0';
        }
        str += mark[curr];
        //cout << pattern << " " << str << "\n";
        return pattern == str;
    }
};