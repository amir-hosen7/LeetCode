class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), len = strs[0].size(), cnt = 0;
        for (int i = 0; i < len; i++) {
            bool ok = 1;
            char prev = 'a';
            for (int j = 0; j < n; j++) {
                if (strs[j][i] < prev) {
                    ok = 0; break;
                }
                prev = strs[j][i];
            }
            if (!ok) cnt++;
        }
        return cnt;
    }
};