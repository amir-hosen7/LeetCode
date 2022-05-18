class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int n=v.size(),idx=0;
		for(int i=0; i<n; i++){
			if(v[i]!=0){
				v[idx++]=v[i];
			}
		}
		for(int i=idx; i<n; i++){
			v[i]=0;
		}
    }
};