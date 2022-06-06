class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int n=a.size(),sum,res=0;
        for(int i=0; i<n; i++){
            sum=0;
            for(auto j:a[i]){
                sum+=j;
            }
            res=max(res, sum);
        }
        return res;
    }
};