class Solution {
public:
    static const int N=50000;
    int lazyF[N*3], lazyB[N*3];
    void propagate(int node, int b, int e, int type){
        if(b!=e){
            if(type==1){
                lazyF[node*2]+=lazyF[node];
                lazyF[node*2+1]+=lazyF[node];
                lazyF[node]=0;
            }
            else{
                lazyB[node*2]+=lazyB[node];
                lazyB[node*2+1]+=lazyB[node];
                lazyB[node]=0;
            }
        }
    }
    
    void update(int node, int b, int e, int L, int R, int type){
        if(lazyF[node]) propagate(node, b, e, 1);
        if(lazyB[node]) propagate(node, b, e, 0);
        if(b>R or e<L or b>e) return;
        if(b>=L and e<=R){
            if(type==1){
                lazyF[node]++;
                propagate(node, b, e, type);
            }
            else{
                lazyB[node]++;
                propagate(node, b, e, type);
            }
            return;
        }
        int mid=b+(e-b)/2;
        update(node*2, b, mid, L, R, type);
        update(node*2+1, mid+1, e, L, R, type);
    }
    
    void query(int node, int b, int e, string &s){
        if(lazyF[node]) propagate(node, b, e, 1);
        if(lazyB[node]) propagate(node, b, e, 0);
        if(b==e){
            if(lazyF[node]>lazyB[node]){
                int dif=(lazyF[node]-lazyB[node])%26;
                cout<<dif<<" "<<b<<" F\n";
                dif=(dif+(s[b-1]-'a'+1))%26;
                if(dif==0) s[b-1]='z';
                else s[b-1]=(char)(dif-1)+'a';
            }
            else if(lazyF[node]<lazyB[node]){
                int dif=(lazyB[node]-lazyF[node])%26;
                //cout<<dif<<" "<<b<<" B\n";
                
                int id=(s[b-1]-'a'+1);
                if(id>dif){
                    id=id-dif-1;
                    s[b-1]=(char)id+'a';
                }
                else{
                    dif-=id;
                    dif=25-dif;
                    s[b-1]=(char)dif+'a';
                }
            }
            return;
        }
        int mid=b+(e-b)/2;
        query(node*2, b, mid, s);
        query(node*2+1, mid+1, e, s);
    }
    
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size(), q=shifts.size();
        for(int i=0; i<q; i++){
            update(1, 1, n, shifts[i][0]+1, shifts[i][1]+1, shifts[i][2]);
        }
        query(1, 1, n, s);
        return s;
    }
};



