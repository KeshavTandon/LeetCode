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
    ListNode* reverse(ListNode* node)
    {
        //I will recieve one node and i will reverse from it
        ListNode* prev=NULL;
        ListNode* nextNode=node;
        while(node)
        {
            nextNode=node->next;
            node->next=prev;
            prev=node;
            node=nextNode;
        }
        return prev;
        
    }
    bool isPalindrome(ListNode* head) {
        if(!head || head->next==NULL) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        ListNode* temp=reverse(slow);
        while(head!=NULL && temp!=NULL)
        {
            if(head->val!=temp->val)
                return false;
            head=head->next;
            temp=temp->next;
        }
        return true;
        
    }
};