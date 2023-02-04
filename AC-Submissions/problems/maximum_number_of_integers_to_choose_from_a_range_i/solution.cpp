class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int, int> mark;
        for (auto i : banned) {
            mark[i] = 1;
        }
        int sum = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (mark[i] == 0) {
                if ((sum + i) <= maxSum) {
                    cnt++;
                    sum += i;
                }
            }
        }
        return cnt;
    }
};