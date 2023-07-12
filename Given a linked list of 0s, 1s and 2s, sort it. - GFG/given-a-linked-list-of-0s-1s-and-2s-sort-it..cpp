//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
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
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
    Node* zero_head=new Node(-1);
    Node* zero_tail=zero_head;

    Node* one_head=new Node(-1);
    Node* one_tail=one_head;

    Node* two_head=new Node(-1);
    Node* two_tail=two_head;

    Node* curr=head;
    while(curr!=NULL)
    {
        if(curr->data==0)
        {
            Node* temp=curr;
            curr=curr->next;
            temp->next=NULL;
            zero_tail->next=temp;
            zero_tail=temp;
        }
        else if(curr->data==1)
        {
            Node* temp=curr;
            curr=curr->next;
            temp->next=NULL;
            one_tail->next=temp;
            one_tail=temp;
        }
        else{
            Node* temp=curr;
            curr=curr->next;
            temp->next=NULL;
            two_tail->next=temp;
            two_tail=temp;
        }
    }

    //removing the -1 of all the LL

    Node* temp=one_head;
    one_head=one_head->next;
    temp->next=NULL;
    delete temp;

    temp=two_head;
    two_head=two_head->next;
    temp->next=NULL;
    delete temp;

    if(one_head!=NULL)
    {
        zero_tail->next=one_head;
        if(zero_head!=NULL)
        one_tail->next=two_head;
    }
    else{
        if(two_head!=NULL)
        zero_tail->next=two_head;
    }

    temp=zero_head;
    zero_head=zero_head->next;
    temp->next=NULL;
    delete temp;

    return zero_head;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends