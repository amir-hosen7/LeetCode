class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int,int>>v;
        for(int i=0; i<n; i++){
            v.push_back({intervals[i][0], intervals[i][1]});
        }
        sort(v.begin(),v.end());
        int cnt=0,L=v[0].first,R=v[0].second;
        for(int i=1; i<n; i++){
             if(L==v[i].first and R==v[i].second){
                cnt++;
                continue;
            }
            if(R>v[i].first){
                cnt++;
                if(v[i].second<=R){
                    L=v[i].first, R=v[i].second;
                }
            }
            else{
                L=v[i].first, R=v[i].second;
            }
        }
        return cnt;
    }
};