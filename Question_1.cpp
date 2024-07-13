#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    
};


void printList(Node *head)
{
    Node *temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}
void reverse(Node* head)
{
    Node* prev=NULL;
    Node* curr=head;
    Node* forw=NULL;
    while(curr!=NULL)
    {
        forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    while(prev!=NULL)
    {
        cout<<prev->data<<" ";
        prev=prev->next;
    }
}
Node* createNode(int data)
{
    Node* newNode=new Node();
    newNode->data=data;
    newNode->next=nullptr;
    return newNode;
}
int main()
{
    int n;
    cout<<"Enter Number Element :";
    cin>>n;
    int t;
    Node* head=NULL, *tail=NULL;
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> t;
        Node* newNode = createNode(t);
        if (head == nullptr) 
        {
            head = newNode;
            tail = head;
        } else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    cout<<"Linked List : ";
    printList(head);
    cout<<endl;
    cout<<"Reversed list : ";
    reverse(head);
    while(head!=nullptr)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    return 0;
}