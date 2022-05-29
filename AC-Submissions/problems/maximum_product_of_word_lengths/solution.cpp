class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size(),res=0;
        for(int i=0; i<n; i++){
            vector<bool>mark(26,0);
            int len=words[i].size();
            for(int j=0; j<len; j++){
                mark[words[i][j]-'a']=true;
            }
            for(int j=i+1; j<n; j++){
                int len2=words[j].size();
                bool ok=true;
                for(int k=0; k<len2; k++){
                    if(mark[words[j][k]-'a']==true){
                        ok=false; break;
                    }
                }
                if(ok==true){
                    res=max(res,len*len2);
                }
            }
        }
        return res;
    }
};