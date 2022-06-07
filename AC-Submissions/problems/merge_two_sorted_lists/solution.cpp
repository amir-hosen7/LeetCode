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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *currNode=NULL, *root=NULL;
        while(list1!=NULL and list2!=NULL){
            int val;
            if(list1->val<list2->val){
                val=list1->val;
                list1=list1->next;
            }
            else{
                val=list2->val;
                list2=list2->next;
            }
            if(root==NULL){
                root=new ListNode(val);
                currNode=root;
            }
            else{
                currNode->next=new ListNode(val);
                currNode=currNode->next;
            }
        }
        while(list1!=NULL){
            if(root==NULL){
                root=new ListNode(list1->val);
                currNode=root;
            }
            else{
                currNode->next=new ListNode(list1->val);
                currNode=currNode->next;
            }
            list1=list1->next;
        }
        while(list2!=NULL){
            if(root==NULL){
                root=new ListNode(list2->val);
                currNode=root;
            }
            else{
                currNode->next=new ListNode(list2->val);
                currNode=currNode->next;
            }
            list2=list2->next;
        }
        return root;
    }
};