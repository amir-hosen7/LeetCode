class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int n=circles.size();
        map<pair<int,int>, bool>cnt;
        for(int i=0; i<n; i++){
            int x=circles[i][0], y=circles[i][1], r=circles[i][2];
            for(int j=0; j<=r; j++){
                for(int k=0; k<=r; k++){
                    if(((j*j)+(k*k))>(r*r)) break;
                    cnt[{x-j, y-k}]=1;
                    cnt[{x-j, y+k}]=1;
                    cnt[{x+j, y-k}]=1;
                    cnt[{x+j, y+k}]=1;
                }
            }
        }
        return cnt.size();
    }
};