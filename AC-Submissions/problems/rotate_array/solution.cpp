class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int n=v.size(),temp;
		k=min(n,k%n);
		for(int i=0; i<n/2; i++){
			temp=v[i];
			v[i]=v[n-i-1];
			v[n-i-1]=temp;
		}
		for(int i=0; i<k/2; i++){
			temp=v[i];
			v[i]=v[k-i-1];
			v[k-i-1]=temp;
		}
		for(int i=0; i<(n-k)/2; i++){
			temp=v[k+i];
			v[k+i]=v[n-i-1];
			v[n-i-1]=temp;
		}
    }
};