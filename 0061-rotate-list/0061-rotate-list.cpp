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
    int calculateLength(ListNode* head)
    {
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* nextNode;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            nextNode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextNode;
        }
        return prev;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
       int count=calculateLength(head);
       int rotate=k%count;
       ListNode* curr=head;
       int tot=1;
       while(tot<count-rotate)
       {
           // cout << curr->val << endl;?
           tot++;
           curr=curr->next;
       }
        ListNode* newReverse=reverseLL(curr->next);
        curr->next=NULL;
        ListNode* firstReverse=reverseLL(head);
        
        head->next=newReverse;
        ListNode* ans=reverseLL(firstReverse);
        return ans;
        
    }
    // 1 2 3 4 5
    // 3 2 1 5 4
    
};