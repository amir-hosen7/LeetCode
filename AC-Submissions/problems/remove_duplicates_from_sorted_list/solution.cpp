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
        ListNode *currNode=root;
        while(currNode->next!=NULL){
            ListNode *prev=currNode;
            int flag=0;
            while(1){
                if(currNode->next==NULL){flag=1; break;}
                currNode=currNode->next;
                if(prev->val!=currNode->val){break;}
            }
            if(prev->val==currNode->val){
                prev->next=NULL;
                break;
            }
            else{
                prev->next=currNode;
            }
            if(flag==1){break;}
        }
        return root;
    }
};