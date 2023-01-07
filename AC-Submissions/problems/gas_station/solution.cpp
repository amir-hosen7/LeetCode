class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            gas.push_back(gas[i]);
            cost.push_back(cost[i]);
        }
        int curr = 0, cnt = 0, idx = -1;
        for (int i = 0; i < (2 * n); i++) {
            curr += gas[i];
            if (cost[i] > curr) {
                curr = 0, cnt = 0;
            }
            else {
                cnt++;
                curr -= cost[i];
                if (cnt == n) {
                    idx = i - cnt + 1; break;
                }
            }
        }
        return idx;
    }
};