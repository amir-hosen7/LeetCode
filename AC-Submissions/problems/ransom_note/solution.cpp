class Solution {
public:
    bool canConstruct(string a, string b) {
        int n=a.size(), m=b.size();
        unordered_map<int, int> cnt, cnt2;
        for(int i=0; i<m; i++){
            int id=b[i]-'a'+1;
            cnt[id]++;
        }
        for(int i=0; i<n; i++){
            int id=a[i]-'a'+1;
            cnt2[id]++;
        }
        for(auto i:cnt2){
            if(i.second>cnt[i.first]) return false;
        }
        return true;
    }
};