class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        int h=g.size(), cnt=0;
        unordered_map<char, int> mark;
        mark['M']=-1, mark['P']=-1, mark['G']=-1;
        for(int i=h-1; i>=0; i--){
            int siz=g[i].size();
            for(int j=0; j<siz; j++){
                if(g[i][j]=='M' and mark['M']==-1){
                    mark['M']=i;
                    cnt++;
                }
                else if(g[i][j]=='P' and mark['P']==-1){
                    mark['P']=i;
                    cnt++;
                }
                else if(g[i][j]=='G' and mark['G']==-1){
                    mark['G']=i;
                    cnt++;
                }
            }
        }
        int time=0;
        for(int i=0; i<h; i++){
            int siz=g[i].size();
            for(int j=0; j<siz; j++){
                if(g[i][j]=='M'){
                    time++;
                }
                else if(g[i][j]=='P'){
                    time++;
                }
                else if(g[i][j]=='G'){
                    time++;
                }
            }
            //cout<<time<<" "<<cnt<<"\n";
            if(i) time+=(cnt*t[i-1]);
            if(mark['M']==i) cnt--;
            if(mark['P']==i) cnt--;
            if(mark['G']==i) cnt--;
        }
        return time;
    }
};





