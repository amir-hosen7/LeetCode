class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        stack<int>st;
        vector<int>v(n,0);
        int res=0;
        for(int i=0; i<n; i++){
        	if(s[i]=='('){
        		st.push(i);
        	}
        	else{
        		if(!st.empty()){
        			int tp=st.top();
        			st.pop();
        			v[tp]=i-tp+1;
        			if(tp>0){
        				v[tp]+=v[tp-1];
        			}
        			v[i]=v[tp];
        			res=max(res,v[i]);
        		}
        	}
        }
        return res;
    }
};