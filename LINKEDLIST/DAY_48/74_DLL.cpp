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

Node* deleteHead(Node* head){
    if(head==NULL||head->next==NULL) return NULL;

    Node* temp=head;
    head=head->next;
    head->back=nullptr;
    temp->next=nullptr;

    free(temp);
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL||head->next==NULL) return NULL;

    Node* tail=head;
    while(tail->next->next){
        tail=tail->next;
    }
    tail->next->back=nullptr;
    free(tail->next);
    tail->next=nullptr;
    return head;
}

Node* deleteKthNode(Node* head,int k){
    if(head==nullptr) return nullptr;

    int cnt=0;
    Node* temp=head;
    while(temp){
        cnt++;
        if(cnt==k) break;

        temp=temp->next;
    }
    
    Node* prev=temp->back;
    Node* front=temp->next;

    if(front==NULL&&prev==NULL){
        delete temp;
        return NULL;
    }
    else if(prev==NULL){
        return deleteHead(head);
    }
    else if(front==NULL)
    return deleteTail(head);

    else{
        prev->next=front;
        front->back=prev;
        delete temp;
        return head;
    }
}

void deleteNode(Node* temp){
    Node* prev=temp->back;
    Node* front=temp->next;

    if(front==nullptr){
        prev->next=nullptr;
        temp->back=nullptr;
        delete temp;
        return;
    }

    prev->next=front;
    front->back=prev;
    temp->next=temp->back=nullptr;
    delete temp;
}

int main(){
    vector<int>arr={12,5,8,7};
    Node* head=convertArr2DLL(arr);
    print(head);cout<<"\n";

    // head=deleteHead(head);
    // print(head);cout<<"\n";

    // head=deleteTail(head);
    // print(head);cout<<"\n";

    // head=deleteKthNode(head,1);
    // print(head);cout<<"\n";

    deleteNode(head->next->next);
    print(head);cout<<"\n";
    return 0;
}