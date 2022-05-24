class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0; i<n; i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){return false;}
                char ch=st.top();
                if(s[i]==')'){
                    if(ch!='('){return false;}
                }
                else if(s[i]=='}'){
                    if(ch!='{'){return false;}
                }
                else{
                    if(ch!='['){return false;}
                }
                st.pop();
            }
        }
        if(st.empty()){return true;}
        return false;
    }
};