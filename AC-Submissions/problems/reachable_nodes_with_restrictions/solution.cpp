class Solution {
public:
    int node;
    bool vis[100010];
    unordered_map<int,bool>mark;
    vector<int>adj[100010];
    void dfs(int root){
        vis[root]=1;
        node++;
        for(auto i:adj[root]){
            if(vis[i]==0 and mark[i]==0){
                dfs(i);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int siz=edges.size();
        for(int i=0; i<siz; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(auto i:restricted){
            mark[i]=1;
        }
        dfs(0);
        return node;
    }
};