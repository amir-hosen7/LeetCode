class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans = 0;
        for(int i = 0; i < J.length(); i++)
        {
            for(int k = 0; k < S.length(); k++)
            {
                if(J[i] == S[k])
                {
                    ans++;
                    S[k] = '0';
                }
            }
        }
        return ans;
    }
};