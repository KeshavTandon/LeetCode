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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
         ListNode* startNode;
        ListNode* endNode;
        int count =0;
        ListNode* temp1 = list1;
        while(count<b){
            if(count==a-1){
                startNode = temp1;
            }
            temp1 = temp1->next;
            count++;
        }
        endNode = temp1;
     
        ListNode* temp = list2;
        while(temp->next!=NULL){
            temp =  temp->next;
        }
        temp->next = endNode->next;
        startNode->next = list2;
        return list1;
    }
};