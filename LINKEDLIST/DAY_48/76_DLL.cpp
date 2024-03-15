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

void reverseDLL(Node* head){
    Node* temp=head;
    stack<int>s;
    while(temp){
        s.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(!s.empty()){
        temp->data=s.top();
        temp=temp->next;
        s.pop();
    }
}

Node* reverseDLL2(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    while(curr){
        prev=curr->back;
        curr->back=curr->next;
        curr->next=prev;
        curr=curr->back;
    }

    return prev->back;
}

int main(){
    vector<int>arr={12,5,8,7};
    Node* head=convertArr2DLL(arr);
    print(head);cout<<"\n";
    // reverseDLL(head);
    // print(head);cout<<"\n";
    head=reverseDLL2(head);
    print(head);cout<<"\n";
    return 0;
}