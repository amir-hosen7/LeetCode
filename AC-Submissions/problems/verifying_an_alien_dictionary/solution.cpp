class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> mark(30);
        for (int i = 0; i < 26; i++) {
            mark[order[i] - 'a'] = i + 1;
        }
        int n = words.size(), ok = 1;
        for (int i = 0; i < (n - 1) and ok; i++) {
            int j = i + 1;
            int len = words[j].size(), len2 = words[i].size(), flag = 0;
            int mi = min(len, len2);
            for (int k = 0; k < mi; k++) {

                if (mark[words[j][k] - 'a'] > mark[words[i][k] - 'a']) {
                    flag = 1; break;
                }
                if (mark[words[j][k] - 'a'] < mark[words[i][k] - 'a']) {
                    ok = 0; break;
                }
            }
            if (len < len2 and ok and !flag) {
                ok = 0; break;
            }
        }
        return ok;
    }
};