class Solution {
public:
    string oddString(vector<string>& words) {
        int n=words.size();
        vector<int> v[n+5];
        for(int i=0; i<n; i++){
            int siz=words[i].size();
            for(int j=0; j<(siz-1); j++){
                int a=(int)words[i][j+1]-'a', b=(int)words[i][j]-'a';
                v[i].push_back(a-b);
            }
        }
        string res;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(v[i]!=v[j]) cnt++;
            }
            if(cnt==(n-1)){
                res=words[i]; break;
            }
        }
        return res;
    }
};

