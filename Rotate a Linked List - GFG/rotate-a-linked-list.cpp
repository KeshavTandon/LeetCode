//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
 int getLength(Node* head)
{
    int count=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

    Node* rotate(Node* head, int k)
    {
        if(head==NULL) return NULL;
        
        int lengthofLL=getLength(head);
        int actual_rotation=k%lengthofLL;
        if(actual_rotation==0) return head;
        int last_position=actual_rotation-1;
        Node* lastNode=head;
        for(int i=0;i<last_position;i++)
        {
            lastNode=lastNode->next;
        }
        Node* newHead=lastNode->next;
        Node*temp=newHead;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        lastNode->next=NULL;
        temp->next=head;
        return newHead;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends