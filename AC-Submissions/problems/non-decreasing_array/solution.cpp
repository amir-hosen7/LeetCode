class Solution {
public:
    bool checkPossibility(vector<int>& v) {
        int n=v.size(), cnt=0, ok=0, cont=0, prev;
        priority_queue<int>PQ;
        for(int i=0; i<n; i++){
           cont=0;
           while(!PQ.empty()){
               if(PQ.top()>v[i]){
                   cont++;
                   cnt++;
                   if(cont==2){
                       if(!ok){
                           ok++;
                           PQ.push(prev);
                           break;
                       }
                       else{
                           return false;
                       }
                   }
                   if(cnt>=2){
                       return false;
                   }
                   prev=PQ.top();
                   PQ.pop();
               }
               else{
                   break;
               }
           }
           PQ.push(v[i]);
        }
        return true;
    }
};



