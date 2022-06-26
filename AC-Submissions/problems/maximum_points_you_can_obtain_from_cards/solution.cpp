class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        for(int i=0; i<n; i++){
            cardPoints.push_back(cardPoints[i]);
        }
        int m=cardPoints.size();
        int sum=0, cnt=0, L=0, ans=0;
        for(int R=0; R<m; R++){
            cnt++;
            sum+=cardPoints[R];
            if(cnt>k){
                cnt--;
                sum-=cardPoints[L++];
            }
            if(L==0 or (L<n and R>=(n-1))){
                ans=max(ans, sum);
            }
        }
        return ans;
    }
};


