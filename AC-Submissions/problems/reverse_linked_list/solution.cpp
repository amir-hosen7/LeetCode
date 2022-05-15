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
    ListNode* reverseList(ListNode* root) {
        if(root==NULL){
            return NULL;
        }
        ListNode *currNode=root;
        ListNode *prevNode=NULL,*temp;
        while(currNode->next!=NULL){
            temp=currNode;
            currNode=currNode->next;
            temp->next=prevNode;
            prevNode=temp;

        }
        currNode->next=prevNode;
        return currNode;
    }
};