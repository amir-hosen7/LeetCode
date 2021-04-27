class Solution{
public:
	vector<int>calc(vector<int>&v){
        int sz=v.size();
        stack<pair<int,int>>st;
        st.push({-1,0});
        vector<int>expand(sz);
        for(int i=0; i<sz; i++){
            while(st.size()>0){
                pair<int,int>curr=st.top();
                if(v[i]>=curr.first){
                    st.push({v[i],i+1});
                    break;
                }
                else{
                    st.pop();
                    int idx=curr.second-1;
                    expand[idx]=i-idx;
                }
            }
        }
        //cout<<st.size()<<"\n";
        while(st.size()>1){
            pair<int,int>curr=st.top();
            st.pop();
            int idx=curr.second-1;
            //cout<<idx<<" aman\n";
            expand[idx]=sz-idx;
        }
        return expand;
    }

    int solve(vector<int>&A){
        int len=A.size();
        vector<int>left,right;
        left=calc(A);
        reverse(A.begin(),A.end());
        right=calc(A);
        reverse(right.begin(),right.end());
        reverse(A.begin(),A.end());
        int ans=0;
        for(int i=0; i<len; i++){
            ans=max(ans,A[i]*(left[i]+right[i]-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>&matrix){
        int res=0,row=matrix.size();
        if(row==0){
            return res;
        }
        int col=matrix[0].size();
        vector<int>dp(col,0);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int a=matrix[i][j]-'0';
                if(a==1){
                    dp[j]++;
                }
                else{
                    dp[j]=0;
                }
            }
            res=max(res,solve(dp));
        }
        return res;
    }
};