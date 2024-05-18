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
    ListNode* reverseList(ListNode* middleNode)
    {
        ListNode* prev=NULL;
        ListNode* nextNode=middleNode;
        while(middleNode!=NULL)
        {
            nextNode=middleNode->next;
            middleNode->next=prev;
            prev=middleNode;
            middleNode=nextNode;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev;
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        ListNode* temp=reverseList(slow);
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