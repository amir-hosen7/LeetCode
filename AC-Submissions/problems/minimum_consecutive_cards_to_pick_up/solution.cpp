class Solution {
public:
    int minimumCardPickup(vector<int>& v) {
        int n=v.size(),L=0,res=1000000;
		unordered_map<int,int>cnt;
		for(int i=0; i<n; i++){
			cnt[v[i]]++;
			if(cnt[v[i]]>1){
				while(cnt[v[i]]>1){
					cnt[v[L]]--;
					L++;
				}
				res=min(res,i-(L-1)+1);
			}
		}
		if(res==1000000){res=-1;}
		return res;
    }
};