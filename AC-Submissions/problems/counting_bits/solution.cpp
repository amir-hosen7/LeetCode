class Solution {
public:
    vector<int> countBits(int num) {
        int cnt=0;
        vector<int>res;
        for(int i=0; i<=num; i++){
            cnt=0;
            int n=i;
            while(n>0){
                cnt++;
                n=n&(n-1);
            }
            res.push_back(cnt);
        }
        return res;
    }
};