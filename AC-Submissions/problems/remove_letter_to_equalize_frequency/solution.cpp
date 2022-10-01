class Solution {
public:
    bool equalFrequency(string word) {
        int n=word.size();
        unordered_map<int, int> cnt;
        for(int i=0; i<n; i++){
            int id=word[i]-'a'+1;
            cnt[id]++;
        }
        for(int i=1; i<=26; i++){
            if(cnt[i]==0) continue;
            cnt[i]--;
            set<int> st;
            for(int j=1; j<=26; j++){
                if(cnt[j]){
                    st.insert(cnt[j]);
                }
            }
            if(st.size()==1) return true;
            cnt[i]++;
        }
        return false;
    }
};

