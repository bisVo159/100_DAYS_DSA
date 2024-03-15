#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~node(){
        int value=this->data;
        //memory free
       /* if(this->next!=NULL){
            delete next;
               this-> next=NULL;
        }*/
        cout<<" memory is free for node with data "<<value<<endl;
    }
};
// Insertion
void insertAtHead(node *&head, int d)
{
    // new node create
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(node *&tail, int d)
{
    // new node create
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(int position,node* &head){
    //Deleting start node
    if(position==1){
        node* temp=head;
         head=head->next;
         //memory free of start node
         temp->next=NULL;
          delete temp;
    }
    else{
        //deleting any middle or last node
           node* curr=head;
           node* prev=NULL;
           int cnt=1;
           while(cnt<position){
                 prev=curr;
                 curr=curr->next;
                 cnt++;
           }
           prev->next=curr->next;
           curr->next=NULL;
           delete curr;
    }
}

// -----------************-----------
void printRecc(node* head){
    if(head==NULL)
    return;

    cout<<head->data<<" -> ";
    printRecc(head->next);
}

void printKFromEnd(node* head,int& k){
    if(head==NULL)
    return;

    printKFromEnd(head->next,k);
    k--;
    if(k==0)
         cout<<"Kth node from end -> "<<head->data<<endl;
}

node* reverse(node* head,node*& tail){
    if(head->next==NULL){
        tail=head;
        return head;
    }

    node* prev=reverse(head->next,tail);
    tail->next=head;
    tail=head;
    tail->next=NULL;
    return prev;
}

node* reverse2(node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }

    node* chotaHead=reverse2(head->next);
    head->next->next=head;
    head->next=NULL;
    return chotaHead;
}

node* reverseIterative(node* head){
    node* prev=NULL;
    node* curr=head;
    node* forward;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }

    return prev;
}

node* KReverse(node* head,int k){
    if(head==NULL)
        return NULL;
        
    node* prev=NULL;
    node* curr=head;
    node* forward;

    int count=0;
    while(count<k&&curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }

    if(forward!=NULL)
        head->next=KReverse(forward,k);
    return prev;
}

int main()
{

    node *head = NULL;
    node *tail = NULL;

    node* root=new node(5);
    head=tail=root;

          insertAtTail(tail, 4);
          insertAtTail(tail, 1);
          insertAtTail(tail, 3);
          insertAtTail(tail, 2);

    // print using recursion
    printRecc(head);cout<<endl;

    // print Kth node from last
    int k=4;
    printKFromEnd(head,k);

    // reverse a LL
    // node* t=NULL;
    // node* rev=reverse(head,t);
    // printRecc(rev);cout<<endl;

    // node* rev2=reverse2(head);
    //  printRecc(rev2);cout<<endl;

    // Reverse k group nodes
    head=KReverse(head,3);
    printRecc(head);


    return 0;
}