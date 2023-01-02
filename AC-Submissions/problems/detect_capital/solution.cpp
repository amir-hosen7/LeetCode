class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size(), idx = -1, up = 0, low = 0;
        for (int i = 0; i < n; i++) {
            if (word[i] >= 'A' and word[i] <= 'Z') {
                up++, idx = i;
            }
            else low++;
        }
        return (up == n or low == n or (up == 1 and idx == 0));
    }
};