class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>adj[n];
        long long edge=roads.size();
        for(long long i=0; i<edge; i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        vector<long long>node;
        for(long long i=0; i<n; i++){
            node.push_back(adj[i].size());
        }
        sort(node.begin(),node.end());
        reverse(node.begin(),node.end());
        long long res=0;
        long long temp=n;
        for(long long i=0; i<n; i++){
            res+=(node[i]*temp);
            temp--;
        }
        return res;
    }
};