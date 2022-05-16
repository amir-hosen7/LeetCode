/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* root) {
      if(root==NULL){return root;}
      ListNode *currNode=root,*lastNode;
        bool isGetRoot=false,flag=false;
        while(!flag){
            int cnt=0;
            ListNode *prevNode=currNode;
            while(currNode->next!=NULL){
                currNode=currNode->next;
                if(prevNode->val!=currNode->val){
                    break;
                }
                cnt++;
            }
            if(cnt==0){
                if(isGetRoot==false){
                    root=prevNode;
                    lastNode=prevNode;
                    isGetRoot=true;
                }
                else{
                    ListNode *temp=lastNode;
                    temp->next=prevNode;
                    lastNode=prevNode;
                }
            }
            if(currNode->next==NULL){
                if(prevNode->val!=currNode->val){
                    if(isGetRoot==false){
                        root=currNode;
                        lastNode=currNode;
                        isGetRoot=true;
                    }
                    else{
                        ListNode *temp=lastNode;
                        temp->next=currNode;
                        lastNode=currNode;
                    }
                }
                flag=true;
            }
        }
        if(isGetRoot==true){
            lastNode->next=NULL;
        }
        else{
            root=NULL;
        }
        return root;
    }
};