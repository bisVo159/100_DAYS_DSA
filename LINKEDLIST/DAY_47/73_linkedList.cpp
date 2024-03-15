#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    Node(int data){
        this->data = data;
        next=nullptr;
    }
};

Node* convertArr2LL(vector<int>&arr){
    Node* head=nullptr;
    Node* mover=nullptr;

    for(int i=0;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        if(head==nullptr){
            head=mover=temp;
        }else{
            mover->next=temp;
            mover=temp;
        }
    }

    return head;
}

void print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* isertHead(Node* head,int val){
    Node* new_node=new Node(val);
    new_node->next=head;
    return  new_node;
}

Node* insertTail(Node* head,int val){
    if(!head) return new Node(val);
    Node* temp=head;

    while(temp->next){
        temp=temp->next;
    }
    temp->next=new Node(val);
    return head;
}

Node* insertKthPos(Node* head,int k,int val){
        if(head==NULL||k==1){
            Node* new_head=new Node(val);
            new_head->next=head;
            return new_head;
        }

        Node* temp=head;
        Node* prev=head;

        while(temp){
            prev=temp;
            temp=temp->next;
            k--;

            if(k==1){
                Node* new_node=new Node(val);
                prev->next=new_node;
                new_node->next=temp;
                break;
            }
        }

        return head;
}

int main(){
    vector<int>v={1,2,3,4,5,6};
    Node* head=convertArr2LL(v);
    
    cout<<"Linked List is :";
    print(head);
    cout<<"\n";

    head=isertHead(head,100);
    print(head);
    cout<<"\n";

    head=insertTail(head,200);
    print(head);
    cout<<"\n";

    head=insertKthPos(head,8,300);
    print(head);
    cout<<"\n";

    //  Insert Node before Value -> https://www.codingninjas.com/studio/problems/insert-node-before-value_9886941
    return 0;
}