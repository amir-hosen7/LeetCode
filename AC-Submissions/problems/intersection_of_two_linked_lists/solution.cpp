/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int A=0, B=0;
        ListNode *currNode=headA;
        while(currNode!=NULL){
            A++, currNode=currNode->next;
        }
        currNode=headB;
        while(currNode!=NULL){
            B++, currNode=currNode->next;
        }
        int dif=abs(A-B),cnt=0;
        if(A>B){
            while(cnt<dif){
                cnt++;
                headA=headA->next;
            }
        }
        else{
            while(cnt<dif){
                cnt++;
                headB=headB->next;
            }
        }
        while(headA!=NULL and headB!=NULL){
            if(headA==headB){
                return headA;
            }
            headA=headA->next, headB=headB->next;
        }
        return NULL;
    }
};

