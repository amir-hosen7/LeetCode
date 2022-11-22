class Solution {
public:
    int dp[110][10010];
    int solve(int idx, int n, int curr, vector<int>& v){
        if(curr<=0){
            if(curr==0) return 0;
            return 100000;
        }
        if(idx>=n){
            if(curr==0) return 0;
            return 100000;
        }
        int &ret=dp[idx][curr];
        if(ret!=-1) return ret;
        int ans1=1+solve(idx, n, curr-v[idx], v);
        int ans2=min(1+solve(idx+1, n, curr-v[idx], v), solve(idx+1, n, curr, v));
        return ret=min(ans1, ans2);
    }
    
    int numSquares(int n) {
        int N=10000, curr=1;
        vector<int> v;
        while((curr*curr)<=N){
            v.push_back(curr*curr);
            curr++;
        }
        memset(dp, -1, sizeof(dp));
        int siz=v.size();
        return solve(0, siz, n, v);
    }
};

