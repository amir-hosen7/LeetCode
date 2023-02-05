class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), cnt = 0;
        string s = "aeiou";
        vector<int> cum(n + 1);
        cum[0] = 0;
        for (int i = 0; i < n; i++) {
            int start = 0, finish = 0, siz = words[i].size();
            for (int j = 0; j < 5; j++) {
                 if (words[i][0] == s[j]) {
                     start = 1; break;
                 }
            }
            for (int j = 0; j < 5; j++) {
                 if (words[i][siz - 1] == s[j]) {
                     finish = 1; break;
                 }
            }
            if (start and finish) {
                cnt++;
            }
            cum[i + 1] = cnt;
        }
        int q = queries.size();
        vector<int> res;
        for (int i = 0; i < q; i++) {
            int l = queries[i][0] + 1, r = queries[i][1] + 1;
            res.push_back(cum[r] - cum[l - 1]);
        }
        return res;
    }
};