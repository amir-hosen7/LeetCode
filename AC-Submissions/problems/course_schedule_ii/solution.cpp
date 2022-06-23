class Solution {
public:
    bool isCycle;
    int vis[2005];
    vector<int>adj[2005],res;
    void dfs(int root){
        if(isCycle){
            return;
        }
        vis[root]=1;
        for(auto i:adj[root]){
            if(vis[i]==1){
                isCycle=true;
                return;
            }
            if(vis[i]==0){
                dfs(i);
            }
        }
        vis[root]=2;
        res.push_back(root);
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& edge) {
        int siz=edge.size();
        for(int i=0; i<siz; i++){
            adj[edge[i][1]].push_back(edge[i][0]);
        }
        bool ok=1;
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                 dfs(i);
            }
            if(isCycle){
                ok=0;
                break;
            }
        }
        if(!ok){
            res.clear();
            return res;
        }
        else{
            reverse(res.begin(), res.end());
            return res;
        }
    }
};

