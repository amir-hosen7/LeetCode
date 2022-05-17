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
    ListNode* removeNthFromEnd(ListNode* root, int n) {
        if(root->next==NULL){
            return NULL;
        }
        int totalNode=0;
        ListNode *currNode=root;
        while(currNode!=NULL){
            totalNode++;
            currNode=currNode->next;
        }
        currNode=root;
        ListNode *prevNode=root;
        int target=totalNode-n+1,cnt=0;
        while(currNode!=NULL){
            cnt++;
            if(cnt==target){
                if(target==1){
                    root=currNode->next;
                }
                else if(target==totalNode){
                    prevNode->next=NULL;
                }
                else{
                    prevNode->next=currNode->next;
                }
                break;
            }
            prevNode=currNode;
            currNode=currNode->next;
        }
        return root;
    }
};