class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    void solve(int root, int dest, vector<vector<int>>& adj){
        if(root==dest){
            res.push_back(path);
            return;
        }
        for(auto i:adj[root]){
            path.push_back(i);
            solve(i, dest, adj);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        path.push_back(0);
        solve(0,n-1,graph);
        return res;
    }
};