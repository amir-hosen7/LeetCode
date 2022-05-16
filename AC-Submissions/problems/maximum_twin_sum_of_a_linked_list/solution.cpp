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
    int pairSum(ListNode* root) {
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
        ListNode *prevNode=NULL;
        while(mid--){
            ListNode *temp=currNode;
            currNode=currNode->next;
            temp->next=prevNode;
            prevNode=temp;
        }
        int twinSum=0,sum;
        while(1){
            sum=prevNode->val+currNode->val;
            twinSum=max(twinSum,sum);
            if(prevNode->next==NULL){
                break;
            }
            prevNode=prevNode->next;
            currNode=currNode->next;
        }
        return twinSum;
    }
};