class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int l=0, r=1, n=colors.size(), res=0;
        while(r<n){
            if(colors[l]==colors[r]){
                if(neededTime[l]<=neededTime[r]){
                    res+=neededTime[l];
                    l=r, r++;
                }
                else{
                    res+=neededTime[r];
                    r++;
                }
            }
            else{
                l=r, r++;
            }
        }
        return res;
    }
};

