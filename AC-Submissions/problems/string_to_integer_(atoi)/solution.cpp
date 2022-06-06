class Solution {
public:
    int myAtoi(string s) {
        int len=s.size(),idx=0;
        while(s[idx]==' '){
            idx++;
            if(idx==len){
                break;
            }
        }
        long long ans=0;
        bool neg=0,ok=0;
        if(s[idx]=='-'){
            neg=1;
            idx++;
        }
        for(int i=idx; i<len; i++){
            if(s[i]>='0' and s[i]<='9'){
                ok=1;
                ans=ans*10+(s[i]-'0');
                if(neg){
                    if(-ans<=INT_MIN){
                        return INT_MIN;
                    }
                }
                else{
                    if(ans>=INT_MAX){
                        return INT_MAX;
                    }
                }
            }
            else{
                if(i==idx and s[i]=='+' and !neg){
                    continue;
                }
                break;
            }
            //cout<<ans<<" ans\n";
        }
        //cout<<ans<<"\n";
        if(!ok){
            return 0;
        }
        if(neg){
            if(ans==0){
                return 0;
            }
            if(-ans<=INT_MIN){
                return INT_MIN;
            }
            return -ans;
        }
        if(ans>=INT_MAX){
            return INT_MAX;
        }
        return ans;
    }
};