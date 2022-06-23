class Solution {
public:
    bool mark[2005];
    int vis[2005], adj[2005][2005], nodes[2005], idx=0;
    bool isCycle;
    void dfs(int root){
        vis[root]=1;
        for(int i=0; i<idx; i++){
            if(adj[root][nodes[i]]==-1){
                continue;
            }
            if(vis[nodes[i]]==1){
                isCycle=true;
            }
            if(vis[nodes[i]]==0){
                dfs(nodes[i]);
            }
        }
        vis[root]=2;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& edge) {
        int n=edge.size();
        for(int i=0; i<2005; i++){
            for(int j=0; j<2005; j++){
                adj[i][j]=-1;
            }
        }
        for(int i=0; i<n; i++){
            adj[edge[i][1]][edge[i][0]]=1;
            if(mark[edge[i][0]]==0){
                nodes[idx++]=edge[i][0];
                mark[edge[i][0]]=1;
            }
            if(mark[edge[i][1]]==0){
                nodes[idx++]=edge[i][1];
                mark[edge[i][1]]=1;
            }
        }
        for(int i=0; i<idx; i++){
            dfs(nodes[i]);
            if(isCycle){
                return false;
            }
        }
        return true;
    }
};

