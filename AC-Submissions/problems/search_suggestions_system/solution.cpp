class node{
public:
	node *next[30];
	vector<string>list;
	node(){
		for(int i=0; i<26; i++){
			next[i]=NULL;
		}
	}
}*root;

class Solution{
public:
	vector<vector<string>>suggestedProducts(vector<string>&products, string searchWord){
        root=new node();
        int len=products.size();
        sort(products.begin(),products.end());
        for(int i=0; i<len; i++){
        	node *curr=root;
			int len=products[i].size();
			for(int j=0; j<len; j++){
				int id=products[i][j]-'a';
				if(curr->next[id]==NULL){
					curr->next[id]=new node();
				}
				curr=curr->next[id];
				curr->list.push_back(products[i]);
			}
        }

        len=searchWord.size();
        node *curr=root;
        vector<vector<string>>res(len);
        for(int i=0; i<len; i++){
        	int id=searchWord[i]-'a';
            if(curr->next[id]==NULL){
                break;
            }
        	curr=curr->next[id];
        	int siz=curr->list.size();
        	for(int j=0; j<(min(3,siz)); j++){
        		res[i].push_back(curr->list[j]);
        	}
        }
        return res;
    }
};