/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* oddEvenList(ListNode *head)
        {
            if (!head || head->next == NULL || head->next->next == NULL) return head;
            ListNode *oddHead = head;
            ListNode *oddTail = oddHead;
            ListNode *evenHead = head->next;
            ListNode *evenTail = evenHead;
            int count = 3;
            ListNode *temp = evenHead->next;
            while (temp != NULL)
            {
                if (count & 1)	//odd 
                {
                    
                    oddTail->next = temp;
                    oddTail = oddTail->next;
                }
                else
                {
                     
                    evenTail->next = temp;
                    evenTail = evenTail->next;
                }
                temp = temp->next;
                count++;
            }
            ListNode *temp1 = oddHead;
            ListNode *temp2 = evenHead;
            while (temp2 != NULL)
            {
                cout << "evenHead->";
                cout << temp2->val;
                cout << " ";
                temp2 = temp2->next;
            }
            cout << endl;

           oddTail->next=evenHead;
            evenTail->next=NULL;
            return oddHead;
        }
};