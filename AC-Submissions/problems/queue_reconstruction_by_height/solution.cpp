class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mad;
        int n=people.size();
        for(int i=0;i<n;i++)
        {
            mad.push({people[i][0],people[i][1]});
        }
        
        vector<vector<int>> ans(n,vector<int>(2,-1));
        int prev=-1,count=1;
        while(!mad.empty())
        {
            auto it=mad.top();
            mad.pop();
            
            if(prev==it.first)
            {
                int an=it.second-count;
                for(int i=0;i<n;i++)
                {
                    if(ans[i][0]==-1)
                    {
                        if(an==0)
                        {
                            ans[i][0]=it.first;
                            ans[i][1]=it.second;
                            break;
                        }
                        else{
                            an--;
                        }
                    }
                    
                }
                
                
                count++;
            }
            else{
                int an=it.second;
                for(int i=0;i<n;i++)
                {
                    
                    
                    if(ans[i][0]==-1)
                    {
                        if(an==0)
                        {
                            ans[i][0]=it.first;
                            ans[i][1]=it.second;
                            break;
                        }
                        else{
                            an--;
                        }
                    }
                }
                prev=it.first;
                count=1;
            }
            
        }
        
        return ans;
    }
};