class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum = 0, cnt = 0;
        for (auto i : costs) {
            if ((sum + i) <= coins) {
                sum += i, cnt++;
            }
        }
        return cnt;
    }
};