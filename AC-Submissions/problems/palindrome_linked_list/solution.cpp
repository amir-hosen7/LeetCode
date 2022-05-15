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
    bool isPalindrome(ListNode* root) {
        int totalNode=1,mid;
        ListNode *currNode=root;
        while(currNode->next!=NULL){
            totalNode++;
            currNode=currNode->next;
        }
        if(totalNode==1){
            return true;
        }
        mid=totalNode/2;
        int cnt=0;
        currNode=root;
        ListNode *prev=NULL,*temp;
        while(1){
            cnt++;
            temp=currNode;
            currNode=currNode->next;
            temp->next=prev;
            prev=temp;
            if(cnt==mid){break;}
        }
        if(totalNode%2==1){
            currNode=currNode->next;
        }
        while(mid--){
            if(temp->val!=currNode->val){
                return false;
            }
            temp=temp->next;
            currNode=currNode->next;
        }
        return true;
    }
};