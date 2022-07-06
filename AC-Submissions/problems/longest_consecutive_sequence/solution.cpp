class Solution {
public:
    int find(int r, vector<int>& rep){
        if(rep[r]==r) return r;
        return rep[r]=find(rep[r], rep);
    }
    
    void join(int u, int v, vector<int>& rep, vector<int>& rank){
        u=find(u, rep), v=find(v, rep);
        if(u!=v){
            if(rank[v]>rank[u]){
                swap(u,v);
            }
            rep[v]=u, rank[u]+=rank[v];
        }
    }
    
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        vector<int>rep(n), rank(n);
        for(int i=0; i<n; i++){
            rep[i]=i, rank[i]=1;
        }
        unordered_map<int,int>mark;
        for(int i=0; i<n; i++){
            if(mark.find(nums[i]) != mark.end()){
                continue;
            }
            if(mark.find(nums[i]-1) != mark.end()){
                join(mark[nums[i]-1], i, rep, rank);
            }
            if(mark.find(nums[i]+1) != mark.end()){
                join(mark[nums[i]+1], i, rep, rank);
            }
            mark[nums[i]]=i;
        }
        int ans=0;
        for(auto i:rank){
            ans=max(ans, i);
        }
        return ans;
    }
};


