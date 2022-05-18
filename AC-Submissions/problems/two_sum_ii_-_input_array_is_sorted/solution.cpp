class Solution {
public:
    vector<int> twoSum(vector<int>& v, int sum) {
        int n=v.size();
		int L=0,R=n-1;
		while((v[L]+v[R])!=sum){
			if((v[L]+v[R])>sum){
				R--;
			}
			else{
				L++;
			}
		}
        return {L+1,R+1};
    }
};