class Solution {
public:
    
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        for (int i = 0; i < k; i++) {
            int mx = 0, idx;
            for (int j = 0; j < n; j++) {
                if (gifts[j] > mx) {
                    mx = gifts[j], idx = j;
                }
            }
            gifts[idx] = sqrt(gifts[idx]);
        }
        long long res = 0;
        for (auto i : gifts) {
            res += i;
        }
        return res;
    }
};