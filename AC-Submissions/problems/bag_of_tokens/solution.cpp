class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int L=0, R=tokens.size()-1, score=0, res=0;
        while(L<=R){
            if(power>=tokens[L]){
                score++;
                power-=tokens[L++];
            }
            else{
                if(score){
                    score--;
                    power+=tokens[R--];
                }
                else{
                    break;
                }
            }
            res=max(res, score);
        }
        return res;
    }
};