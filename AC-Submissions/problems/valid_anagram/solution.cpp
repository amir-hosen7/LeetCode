class Solution {
public:
    bool isAnagram(string s, string p) {
        int plen=p.size(),slen=s.size();
        if(plen!=slen){return false;}
        vector<int>cnt(26,0),cnt2(26,0);
        for(int i=0; i<plen; i++){
            cnt[p[i]-'a']++;
            cnt2[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(cnt[i]!=cnt2[i]){return false;}
        }
        return true;
    }
};