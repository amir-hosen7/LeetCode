class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[1]==b[1]) return a[0]>b[0];
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size(), ans=0;
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        for(int i=0; i<n and truckSize; i++){
            if(boxTypes[i][0]<=truckSize){
                ans+=(boxTypes[i][1]*boxTypes[i][0]);
                truckSize-=boxTypes[i][0];
            }
            else{
                ans+=(boxTypes[i][1]*truckSize);
                truckSize=0;
            }
        }
        return ans;
    }
};