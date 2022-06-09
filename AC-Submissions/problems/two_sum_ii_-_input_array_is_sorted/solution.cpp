class Solution {
public:
    vector<int> twoSum(vector<int>& v, int sum) {
        int n=v.size(),L,R;
		for(int i=0; i<n; i++){
			L=i,R=upper_bound(v.begin(),v.end(),sum-v[i])-v.begin();
			if((v[i]+v[R-1])==sum){
                break;
            }
		}
        return {L+1,R};
    }
};