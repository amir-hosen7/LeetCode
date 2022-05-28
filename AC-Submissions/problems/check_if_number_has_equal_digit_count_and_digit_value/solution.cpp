class Solution {
public:
    bool digitCount(string num) {
        int n=num.size();
        vector<int>cnt(10,0);
        for(int i=0; i<n; i++){
        	int id=num[i]-'0';
        	cnt[id]++;
        }
        for(int i=0; i<n; i++){
        	int id=num[i]-'0';
        	if(cnt[i]!=id){
        		return false;
        	}
        }
        return true;
    }
};