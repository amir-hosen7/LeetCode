class Solution {
public:
    int maxRepOpt1(string text) {
        bool ok=0;
        int n=text.size(),cnt=1;
        vector<int>freq(26,0);
        vector<pair<int, char>>v;
        for(int i=0; i<(n-1); i++){
            freq[text[i]-'a']++;
            if(text[i]==text[i+1]){
                ok=1, cnt++;
            }
            else{
                v.push_back({cnt,text[i]});
                ok=0, cnt=1;
            }
        }
        if(ok or n==1){
            v.push_back({cnt, text[n-1]});
        }
        freq[text[n-1]-'a']++;
        int siz=v.size(),res=0;
        // for(int i=0; i<siz; i++){
        //     cout<<v[i].first<<" "<<v[i].second<<"\n";
        // }
        for(int i=1; i<(siz-1); i++){
            if(v[i].first==1){
                int sum=v[i-1].first+v[i+1].first;
                if(v[i-1].second==v[i+1].second){
                    if(freq[v[i-1].second-'a']>sum){
                        sum++;
                    }
                    res=max(res, sum);
                }
            }
        }
        for(int i=0; i<siz; i++){
            if(freq[v[i].second-'a']>v[i].first){
                res=max(res, v[i].first+1);
            }
            else{
                res=max(res, v[i].first);
            }
        }
        return res;
    }
};