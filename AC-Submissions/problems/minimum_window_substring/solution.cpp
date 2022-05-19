class Solution {
public:
    string minWindow(string s, string t) {
    	if(s.size()<t.size()){return "";}
        int tlen=t.size();
        vector<int>cnt(55,0);
        for(int i=0; i<tlen; i++){
        	int id=t[i]-'a'+26;
        	if(t[i]>='A' and t[i]<='Z'){
        		id=t[i]-'A';
        	}
        	cnt[id]++;
        }
        int slen=s.size(),ok=0;
        int L=0,R=slen,a=0,b;
        vector<int>currCnt(55);
        while(L<=R){
        	int mid=L+(R-L)/2,flag=0,LL=0;
        	for(int i=0; i<=52; i++){
        		currCnt[i]=0;
        	}
        	for(int i=0; i<slen; i++){
        		int id=s[i]-'a'+26;
        		if(s[i]>='A' and s[i]<='Z'){
        			id=s[i]-'A';
        		}
        		currCnt[id]++;
        		if(i>=mid){
        			int id=s[LL]-'a'+26;
	        		if(s[LL]>='A' and s[LL]<='Z'){
	        			id=s[LL]-'A';
	        		}
	        		currCnt[id]--;
	        		LL++;
        		}
        		int ck=1;
        		for(int j=0; j<=52; j++){
        			if(currCnt[j]<cnt[j]){
        				ck=0; break;
        			}
        		}
        		if(ck==1){
        			a=LL,b=i;
        			flag=1; break;
        		}
        	}
        	if(flag==1){
        		ok=1;
        		R=mid-1;
        	}
        	else{
        		L=mid+1;
        	}
        }
        if(ok==0){return "";}
        t="";
        for(int i=a; i<=b; i++){
        	t+=s[i];
        }
        return t;
    }
};