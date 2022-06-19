class Solution {
public:
    struct ListNode{
        vector<string>list;
        ListNode *next[30];
        ListNode(){
            for(int i=0; i<=26; i++){
                next[i]=NULL;
            }
        }
    }*root;
    
    void insert(string &s){
        int n=s.size();
        ListNode *curr=root;
        for(int i=0; i<n; i++){
            int id=s[i]-'a';
            if(curr->next[id]==NULL){
                curr->next[id]=new ListNode();
            }
            curr=curr->next[id];
            if(curr->list.size()<3){
                curr->list.push_back(s);
            }
        }
    }
    
    vector<vector<string>> query(string &s){
        int n=s.size(),idx=0;
        ListNode *curr=root;
        vector<vector<string>>res(n);
        for(int i=0; i<n; i++){
            int id=s[i]-'a';
            if(curr->next[id]==NULL){
                break;
            }
            curr=curr->next[id];
            res[i]=curr->list;
        }
        return res;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root=new ListNode();
        int n=products.size();
        sort(products.begin(), products.end());
        for(int i=0; i<n; i++){
            insert(products[i]);
        }
        return query(searchWord);
    }
};



