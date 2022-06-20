class Solution {
public:
    struct ListNode{
      bool endmark;
      ListNode *next[30];
        ListNode(){
            endmark=false;
            for(int i=0; i<=26; i++){
                next[i]=NULL;
            }
        }
    }*root;
    
    static bool cmp(string &a, string &b){
        return a.size()>b.size();
    }
    
    int insert(string &s){
        int n=s.size();
        reverse(s.begin(),s.end());
        ListNode *curr=root;
        bool isNew=false;
        for(int i=0; i<n; i++){
            int id=s[i]-'a';
            if(curr->next[id]==NULL){
                isNew=true;
                curr->next[id]=new ListNode();
            }
            curr=curr->next[id];
        }
        if(isNew){
            return n+1;
        }
        return 0;
    }
    
    
    int minimumLengthEncoding(vector<string>& words) {
        int n=words.size();
        root=new ListNode();
        int ans=0;
        sort(words.begin(), words.end(), cmp);
        for(int i=0; i<n; i++){
            ans+=insert(words[i]);
        }
        return ans;
    }
};



