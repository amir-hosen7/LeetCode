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
    ListNode* deleteMiddle(ListNode* root) {
        if(root->next==NULL){
            return NULL;
        }
        int totalNode=0;
        ListNode *currNode=root;
        while(1){
            totalNode++;
            if(currNode->next==NULL){
                break;
            }
            currNode=currNode->next;
        }
        int mid=totalNode/2;
        currNode=root;
        ListNode *prevNode;
        while(mid--){
            prevNode=currNode;
            currNode=currNode->next;
        }
        prevNode->next=currNode->next;
        return root;
    }
};