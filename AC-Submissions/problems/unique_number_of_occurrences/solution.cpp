class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>Map,cnt;
        int n=arr.size();
        for(int i=0; i<n; i++){
            Map[arr[i]]++;
        }
        for(auto i:Map){
            cnt[i.second]++;
            if(cnt[i.second]>1){return false;}
        }
        return true;
    }
};