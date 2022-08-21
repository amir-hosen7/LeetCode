class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size(), prev = 0, currFuel = startFuel, ans=0, ok=1;
        if(target<=startFuel) return 0;
        priority_queue<int> PQ;
        for(int i=0; i<n; i++) {
            while(currFuel < (stations[i][0]-prev) and !PQ.empty()) {
                ans++;
                currFuel += PQ.top();
                PQ.pop();
            }
            if(currFuel < (stations[i][0]-prev)) {
                ok=0; break;
            }
            currFuel-=(stations[i][0]-prev);
            PQ.push(stations[i][1]);
            prev=stations[i][0];
            if(currFuel>=(target-stations[i][0])) {
                break;
            }
        }
        while(currFuel<(target-prev) and !PQ.empty()){
            currFuel += PQ.top();
            PQ.pop();
            ans++;
        }
        if(currFuel<(target-prev) or !ok) ans=-1;
        return ans;
    }
};

