class Solution {
public:
    void reverseString(vector<char>& v) {
        int n=v.size();
        char temp;
		for(int i=0; i<n/2; i++){
			temp=v[i];
			v[i]=v[n-i-1];
			v[n-i-1]=temp;
		}
    }
};