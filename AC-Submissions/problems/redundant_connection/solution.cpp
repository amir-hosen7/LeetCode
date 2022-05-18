class Solution {
public:
    int rep[1010];
    int Find(int r){
        if(r==rep[r]){return r;}
        return rep[r]=Find(rep[r]);
    }
    
    bool Union(int a, int b){
        a=Find(a),b=Find(b);
        if(a!=b){
            rep[b]=a;
        }
        else{
            return true;
        }
        return false;
    }
    
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int node=edges.size();
        for(int i=0; i<1010; i++){
            rep[i]=i;
        }
        int idx;
		for(int i=0; i<node; i++){
			if(Union(edges[i][0],edges[i][1])==true){
                idx=i; break;
            }
		}
        return edges[idx];
    }
};