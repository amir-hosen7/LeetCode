class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int,int>>A(n);
        for(int i=0; i<n; i++){
            A[i]={intervals[i][0],intervals[i][1]};
        }
        sort(A.begin(),A.end());
        int currStart=A[0].first;
        int currEnd=A[0].second;
        vector<vector<int>>res;
        for(int i=1; i<n; i++){
            if(A[i].first>currEnd){
                res.push_back({currStart,currEnd});
                currStart=A[i].first;
                currEnd=A[i].second;
            }
            else{
                currEnd=max(currEnd,A[i].second);
            }
        }
        res.push_back({currStart,currEnd});
        return res;
    }
};