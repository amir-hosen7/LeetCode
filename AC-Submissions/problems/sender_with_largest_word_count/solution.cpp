class Solution {
public:
	int solve(string s){
		int n=s.size(),cnt=1;
		for(int i=0; i<n; i++){
			if(s[i]==' '){
				cnt++;
			}
		}
		return cnt;
	}
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n=messages.size(),Max=0;
        unordered_map<string,int>Map;
        for(int i=0; i<n; i++){
        	Map[senders[i]]+=solve(messages[i]);
        	Max=max(Map[senders[i]],Max);
        }
        string res="";
        for(auto i:Map){
        	if(i.second==Max){
        		res=max(res,i.first);
        	}
        }
        return res;
    }
};