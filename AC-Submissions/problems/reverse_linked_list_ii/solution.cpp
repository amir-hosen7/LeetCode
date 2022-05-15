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
    ListNode* reverseBetween(ListNode* root, int L, int R) {
        int cnt=0;
        if(L==R){
            return root;
        }
        ListNode *currNode=root;
        ListNode *start=NULL,*end=NULL;
        while(1){
            cnt++;
            if(cnt<L){
                start=currNode;
            }
            if(cnt>R){
                end=currNode;
                break;
            }
            if(currNode->next==NULL){break;}
            currNode=currNode->next;
        }
        ListNode *prev=end,*temp;
        if(start==NULL){
            currNode=root;
        }
        else{
            currNode=start->next;
        }
        while(currNode->next!=end){
            temp=currNode;
            currNode=currNode->next;
            temp->next=prev;
            prev=temp;
        }
        currNode->next=prev;
        if(start!=NULL){
            start->next=currNode;
        }
        else{
            root=currNode;
        }
        return root;
    }
};