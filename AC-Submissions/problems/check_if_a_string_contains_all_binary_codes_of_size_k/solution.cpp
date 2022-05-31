class Solution {
public:
    string getStr(int i, int k){
        int idx=k-1;
        vector<char>v(k,'0');
        while(i>0){
            if(i%2==1){
                v[idx]='1';
            }
            idx--;
            i/=2;
        }
        string s="";
        for(int i=0; i<k; i++){
            s+=v[i];
        }
        return s;
    }
    
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        unordered_map<string,bool>mark;
        for(int i=0; i<=(n-k); i++){
            string temp=s.substr(i,k);
            mark[temp]=true;
        }
        for(int i=0; i<(1<<k); i++){
            if(mark[getStr(i,k)]==false){
                return false;
            }
        }
        return true;
    }
};