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
    ListNode* removeElements(ListNode* root, int val) {
        if(root==NULL){
            return NULL;
        }
        bool flag=false;
        ListNode *currNode=root,*prevNode=root;
        while(currNode!=NULL){
            if(currNode->val==val){
                prevNode->next=currNode->next;
            }
            else{
                if(flag==false){
                    flag=true;
                    root=currNode;
                }
                prevNode=currNode;
            }
            currNode=currNode->next;
        }
        if(flag==false){return NULL;}
        return root;
    }
};