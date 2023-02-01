class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int mi = min(n, m);
        string res, curr;
        for (int i = 0; i < mi; i++) {
            curr += str1[i];
            if (n % (i + 1) or m % (i + 1)) continue;
            int cnt = 0, tot = n / (i + 1), idx = 0;
            for (int j = 0; j < n; j++) {
                if (str1[j] == curr[idx]) {
                    idx++;
                    if (idx == (i + 1)) {
                        cnt++, idx = 0;
                    }
                }
            }
            if (cnt != tot) continue;
            cnt = 0, tot = m / (i + 1);
            for (int j = 0; j < m; j++) {
                if (str2[j] == curr[idx]) {
                    idx++;
                    if (idx == (i + 1)) {
                        cnt++, idx = 0;
                    }
                }
            }
            if (cnt != tot) continue;
            res = curr;
        }
        return res;
    }
};
