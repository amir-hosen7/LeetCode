class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        while(x>0 or y>0){
            int a = x%2;
            int b = y%2;
            x/=2; y/=2;
            if(a!=b) ans++;
        }
        return ans;
    }
};