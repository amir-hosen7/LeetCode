

        
    class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int plen=p.size();
        vector<int>cnt(26,0);
        for(int i=0; i<plen; i++){
            cnt[p[i]-'a']++;
        }
        int slen=s.size(),L=0;
        vector<int>currCnt(26,0),res;
        if(plen>slen){return res;}
        for(int i=0; i<slen; i++){
            currCnt[s[i]-'a']++;
            if(i>=plen){
                currCnt[s[L]-'a']--;
                L++;
            }
            int ok=1;
            for(int j=0; j<26; j++){
                if(currCnt[j]!=cnt[j]){
                    ok=0; break;
                }
            }
            if(ok==1){
                res.push_back(L);
            }
        }
        return res;
    }
};
