class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size(),ok=0;
        string temp;
         vector<string>A;
        vector<vector<string>>res;
       	vector<pair<string,int>>v[101];
        for(int i=0; i<n; i++){
        	temp=strs[i];
        	sort(temp.begin(),temp.end());
        	int siz=temp.size();
        	if(siz==0){
                ok=1;
        		A.push_back(strs[i]);
        	}
        	else{
        		v[siz].push_back({temp,i});
        	}
        }
        if(ok==1){
            res.push_back(A);
            A.clear();
        }
        for(int i=1; i<=100; i++){
        	int siz=v[i].size();
        	if(siz>0){
        		sort(v[i].begin(),v[i].end());
        		for(int j=0; j<(siz-1); j++){
        			if(v[i][j].first==v[i][j+1].first){
        				A.push_back(strs[v[i][j].second]);
        			}
        			else{
        				A.push_back(strs[v[i][j].second]);
        				res.push_back(A);
        				A.clear();
        			}
        		}
        		A.push_back(strs[v[i][siz-1].second]);
        		res.push_back(A);
        		A.clear();
        	}
        }
        return res;
    }
};