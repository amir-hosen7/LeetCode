class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n=s.size();
		int L=0, w=0, ans=100000, ok=0;
		for(int i=0; i<n; i++){
            if(i>=(k-1)) ok=1;
			if(s[i]=='W') w++;
			if(i>=k){
				if(s[L++]=='W') w--;
			}
            if(ok) ans=min(ans, w);
		}
        return ans;
    }
};

