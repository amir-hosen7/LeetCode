class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        vector<string> res;
        for(int i=0; i<n; i++){
            int siz=dictionary.size();
            for(int j=0; j<siz; j++){
                int len=queries[i].size(), cnt=0;
                for(int k=0; k<len; k++){
                    if(queries[i][k]!=dictionary[j][k]){
                        cnt++;
                    }
                }
                if(cnt<=2){
                    res.push_back(queries[i]); break;
                }
            }
        }
        return res;
    }
};