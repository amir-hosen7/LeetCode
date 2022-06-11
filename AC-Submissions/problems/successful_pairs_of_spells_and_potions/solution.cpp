class Solution {
public:
    int solve(int val, long long s, vector<int>& v){
        int n=v.size();
        int L=0, R=n-1,ans=n;
        while(L<=R){
            int mid=L+(R-L)/2;
            long long aa=(long long)v[mid]*val;
            if(s<=aa){
                ans=mid;
                R=mid-1;
            }
            else{
                L=mid+1;
            }
        }
        return n-ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(), m=potions.size();
        sort(potions.begin(), potions.end());
        vector<int>res;
        for(int i=0; i<n; i++){
            res.push_back(solve(spells[i], success, potions));
        }
        return res;
    }
};


