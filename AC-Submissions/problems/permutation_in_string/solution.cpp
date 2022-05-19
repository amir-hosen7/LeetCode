class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1=s1.size(),len2=s2.size();
        vector<int>cnt(26,0),currCnt(26,0);
        for(int i=0; i<len1; i++){
        	cnt[s1[i]-'a']++;
        }
        int L=0,ok;
        for(int i=0; i<len2; i++){
        	currCnt[s2[i]-'a']++;
        	ok=1;
        	for(int j=0; j<26; j++){
        		if(cnt[j]!=currCnt[j]){
        			ok=0; break;
        		}
        	}
        	if(ok==1){break;}
        	while(currCnt[s2[i]-'a']>cnt[s2[i]-'a']){
        		currCnt[s2[L]-'a']--; L++;
        	}
        }
        return ok;
    }
};