#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }

    Node(int data){
        this->data = data;
        next=nullptr;
        back=nullptr;
    }
};

Node* convertArr2DLL(vector<int>arr){
    if (arr.empty()) return nullptr;
    Node* head=new Node(arr[0]);
    Node* prev=head;

    for(int i=1;i<arr.size();i++){
        Node* node= new Node(arr[i],nullptr,prev);
        prev->next=node;
        prev=node;
    }

    return head;
}

void print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* insertBeforeHead(Node* head,int val){
    Node* newHead=new Node(val,head,nullptr);
    head->back=newHead;

    return newHead;
}
Node* insertBeforeTail(Node* head,int val){
    if(head==NULL) return insertBeforeHead(head,val);

    Node* tail=head;

    while(tail->next) tail=tail->next;

    Node* prev=tail->back;
    Node* newNode=new Node(val,tail,prev);
    tail->back=newNode;
    if(prev)
    prev->next=newNode;

    return head;
}

Node* insertBeforeKthElement(Node* head,int k,int val){
    if(k==1) return insertBeforeHead(head,val);

    int cnt=0;
    Node* temp=head;
    while(temp){
        cnt++;
        if(cnt==k) break;

        temp=temp->next;
    }

    if(temp==nullptr) return head;
    Node* prev=temp->back;
    Node* newNode=new Node(val,temp,prev);
    temp->back=newNode;
    prev->next=newNode;

    return head;
}

void insertBeforeNode(Node* node,int val){
    Node* prev=node->back;
    Node* newNode=new Node(val,node,prev);
    node->back=newNode;
    prev->next=newNode;
}
int main(){
    vector<int>arr={12,5,8,7};
    Node* head=convertArr2DLL(arr);
    print(head);cout<<"\n";

    head=insertBeforeHead(head,11);
    print(head);cout<<"\n";

    head=insertBeforeTail(head,20);
    print(head);cout<<"\n";

    head=insertBeforeKthElement(head,5,25);
    print(head);cout<<"\n";

    insertBeforeNode(head->next,10);
    print(head);cout<<"\n";
    return 0;
}