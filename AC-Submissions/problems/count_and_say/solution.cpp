class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        while(--n){
            string curr;
            int siz=s.size();
            for(int i=0; i<siz; i++){
                int cnt=1;
                while((i+1)<siz and s[i]==s[i+1]){
                    i++, cnt++;
                }
                curr+=to_string(cnt)+s[i];
            }
            s=curr;
        }
        return s;
    }
};