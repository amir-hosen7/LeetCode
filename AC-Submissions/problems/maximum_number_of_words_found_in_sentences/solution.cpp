class Solution {
public:
    int mostWordsFound(vector<string>& v) {
        int n=v.size(),cnt=1,res=1;
        for(int i=0; i<n; i++){
            string s=v[i];
            cnt=1;
            for(auto i:s){
                if(i==' '){
                    cnt++;
                }
            }
            res=max(res, cnt);
        }
        return res;
    }
};