class Solution {
public:
    static const int N = 110;
    vector<vector<int>> adj[N];
    int solve(int n, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<vector<int>> q;
        q.push({src, 0, 0});
        while (!q.empty()) {
            vector<int> u = q.front();
            int root = u[0], stops = u[1], cost = u[2];
            q.pop();
            if (stops > k) continue;
            int siz = adj[root].size();
            for (int i = 0; i < siz; i++) {
                int child = adj[root][i][0], edgeCost = adj[root][i][1];
                if (dist[child] > (cost + edgeCost) and stops <= k) {
                    dist[child] = cost + edgeCost;
                    q.push({child, stops + 1, dist[child]});
                }
            }
        }
        if (dist[dst] >= 1e9) return -1;
        return dist[dst];
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int siz = flights.size();
        for (int i = 0; i < siz; i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        int res = solve(n, src, dst, k);
        return res;
    }
};
