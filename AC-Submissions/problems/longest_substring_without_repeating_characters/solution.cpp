class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),L=0,res=0;
		unordered_map<char,int>cnt;
		for(int i=0; i<n; i++){
			cnt[s[i]]++;
			if(cnt[s[i]]>1){
				while(cnt[s[i]]>1){
					cnt[s[L]]--;
					L++;
				}
			}
			res=max(res,i-L+1);
		}
		return res;
    }
};