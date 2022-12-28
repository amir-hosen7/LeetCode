class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            pq.push(piles[i]);
        }
        while (k--) {
            int tot = pq.top();
            int curr = tot / 2;
            pq.pop();
            pq.push(tot - curr);
        }
        int res = 0;
        while(!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
