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
    ListNode* deleteMiddle(ListNode* head) {
        int cnt=1;
        ListNode* currNode=head;
        while(currNode->next!=NULL){
            cnt++;
            currNode=currNode->next;
        }
        if(cnt==1) return NULL;
        cnt/=2;
        currNode=head;
        while(cnt>1){
            cnt--;
            currNode=currNode->next;
        }
        currNode->next=currNode->next->next;
        return head;
    }
};