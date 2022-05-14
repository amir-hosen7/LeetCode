class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        int n=intervals.size();
        if(n==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        if(newInterval.size()==0){
            return intervals;
        }
        vector<vector<int>>res;
        int flag=0,ck=0;
        for(int i=0; i<n; i++){
            if(intervals[i][0]>newInterval[1] or intervals[i][1]<newInterval[0]){
                if(flag==1){
                    res.push_back(newInterval);
                    newInterval=intervals[i];
                }
                flag=0;
                res.push_back(intervals[i]);
            }
            else{
                flag=1; ck=1;
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
        }
        if(ck==1){
            if(flag==1){
                res.push_back(newInterval);
            }
        }
        else{
            if(newInterval[0]>intervals[n-1][1]){
                res.push_back(newInterval);
            }
            else if(newInterval[1]<intervals[0][0]){
                res.clear();
                res.push_back(newInterval);
                for(int i=0; i<n; i++){
                    res.push_back(intervals[i]);
                }
            }
            else{
                res.clear();
                flag=0;
                for(int i=0; i<n; i++){
                    if(intervals[i][0]>newInterval[1] and flag==0){
                        flag=1;
                        res.push_back(newInterval);
                    }
                    res.push_back(intervals[i]);
                }
            }
        }
        return res;
    }

};