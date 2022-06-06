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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,tot;
        ListNode *curr, *root=NULL;
        while(l1!=NULL and l2!=NULL){
            tot=l1->val+l2->val+carry;
            carry=tot/10;
            if(root==NULL){
                root=new ListNode(tot%10);
                curr=root;
            }
            else{
                curr->next=new ListNode(tot%10);
                curr=curr->next;
            }
            l1=l1->next, l2=l2->next;
        }
        while(l1!=NULL){
            tot=l1->val+carry;
            carry=tot/10;
            curr->next=new ListNode(tot%10);
            curr=curr->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            tot=l2->val+carry;
            carry=tot/10;
            curr->next=new ListNode(tot%10);
            curr=curr->next;
            l2=l2->next;
        }
        if(carry>0){
            curr->next=new ListNode(carry);
        }
        return root;
    }
};