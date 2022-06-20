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
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode *turtoise=head;
        ListNode *hare=head->next;
        while(hare!=NULL and hare->next!=NULL){
            if(turtoise==hare){
                return true;
            }
            turtoise=turtoise->next;
            hare=hare->next->next;
        }
        return false;
    }
};

