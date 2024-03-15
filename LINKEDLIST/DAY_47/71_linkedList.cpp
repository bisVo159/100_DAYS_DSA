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

void traverseLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int lengthOfLL(Node* head){
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
}


int main(){
    // Node* node=new Node(2,nullptr);
    // cout<<node<<endl;
    // Node x=Node(3,nullptr);
    // cout<<x.data<<endl;
    // Node* node=new Node(2,nullptr);
    // cout<<node->data<<endl;

    vector<int>v={1,2,3,4,5,6};
    Node* head=convertArr2LL(v);
    
    cout<<"Linked List is :";
    traverseLL(head);
    cout<<"\n";

    cout<<lengthOfLL(head)<<endl;
    return 0;
}