class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        vector<int>cnt(26,0);
        unordered_map<int,bool>mark;
        for(int i=0; i<n; i++){
            int id=s[i]-'a';
            cnt[id]++;
        }
        int ans=0;
        for(int i=0; i<26; i++){
            while(cnt[i] and mark[cnt[i]]){
                cnt[i]--, ans++;
            }
            mark[cnt[i]]=true;
        }
        return ans;
    }
};



