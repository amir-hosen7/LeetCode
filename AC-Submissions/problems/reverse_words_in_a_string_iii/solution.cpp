class Solution {
public:
    string reverseWords(string s) {
        int n=s.size(),L=0;
		for(int i=0; i<n; i++){
			if(s[i]==' ' or i==(n-1)){
				char temp;
				int len=(i-L)/2;
				if(i==(n-1)){
					len=(i-L+1)/2;
					i++;
				}
				for(int j=0; j<len; j++){
					temp=s[L+j];
					s[L+j]=s[i-j-1];
					s[i-j-1]=temp;
				}
				L=i+1;
			}
		}
        return s;
    }
};