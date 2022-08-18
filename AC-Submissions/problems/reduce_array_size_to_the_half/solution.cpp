class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> cnt(100010, 0);
        for(auto i : arr) {
            cnt[i]++;
        }
        sort(cnt.begin(), cnt.end());
        reverse(cnt.begin(), cnt.end());
        int ans=0, n=arr.size();
        int siz=n;
        for(int i=0; cnt[i]>0; i++) {
            siz-=cnt[i];
            ans++;
            if(siz<=n/2) break;
        }
        return ans;
    }
};