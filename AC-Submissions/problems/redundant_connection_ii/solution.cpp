class Solution {
public:
	int rep[1010],rank[1010];
	int Find(int r){
		if(rep[r]==r){return r;}
		return rep[r]=Find(rep[r]);
	}
	bool Union(int a,int b){
		a=Find(a),b=Find(b);
		if(a==b){
			return true;
		}
		if(rank[a]<rank[b]){
			swap(rank[a],rank[b]);
		}
		rep[b]=a;
		rank[a]+=rank[b];
		return false;
	}
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges){
		int node=edges.size();
		for(int i=0; i<=node; i++){
			rep[i]=i, rank[i]=1;
		}
		int first=-1,last=-1;
		vector<int>First(node+5,-1);
		for(int i=0; i<node; i++){
			if(First[edges[i][1]]==-1){
				First[edges[i][1]]=i;
			}
			else{
				last=i;
				first=First[edges[i][1]];
				break;
			}
		}
		for(int i=0; i<node; i++){
			if(i!=last){
				bool cycle=Union(edges[i][0],edges[i][1]);
				if(cycle==true){
					if(last==-1){
						return edges[i];
					}
					return edges[first];
				}
			}
		}
		return edges[last];
	}
};