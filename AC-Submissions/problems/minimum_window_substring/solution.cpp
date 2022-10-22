class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(60, 0);
        int slen=s.size();
        for(auto i:t){
            int id=i-'a';
            if(i>='A' and i<='Z'){
                id=i-'A'+26;
            }
            cnt[id]++;
        }
        vector<int> curr(60, 0);
        int L=0, Min=INT_MAX, idx=-1;
        for(int i=0; i<slen; i++){
            int id=s[i]-'a';
            if(s[i]>='A' and s[i]<='Z'){
                id=s[i]-'A'+26;
            }
            curr[id]++;
            bool ok=1;
            while(ok){
                for(int j=0; j<60; j++){
                    if(cnt[j]>curr[j]){
                        ok=0; break;
                    }
                }
                if(ok){
                    if((i-L+1)<Min){
                        Min=i-L+1, idx=L;
                    }
                    int id=s[L]-'a';
                    if(s[L]>='A' and s[L]<='Z'){
                        id=s[L]-'A'+26;
                    }
                    curr[id]--, L++;
                }
            }
        }
        if(idx==-1) return "";
        return s.substr(idx, Min);
    }
};

