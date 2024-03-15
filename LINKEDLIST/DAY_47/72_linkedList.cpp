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

Node* removesHead(Node* head){
    if(head==NULL) return head;

    Node* temp=head;
    head=head->next;

    delete temp;
    return head;
}
void removesTail(Node* head){
    if(head==NULL||head->next==NULL) return ;

    Node* temp=head;
    
    while(temp->next->next){
        temp=temp->next;
    }

    delete temp->next;
    temp->next=NULL;
    // return head;
}

Node* deleteKthNode(Node* head,int k){
    if(head==NULL) return NULL;

    Node* temp=head;
    Node* prev=NULL;

    if(k==1){
        head=head->next;
        delete temp;
        return head;
    }
    while(temp){
        if(k==1){
            prev->next=temp->next;
            delete temp;
            break;
        }

        prev=temp;
        temp=temp->next;
        k--;
    }
    return head;
}

Node* removeEl(Node* head,int el){
    if(head==NULL) return NULL;

    Node* temp=head;
    Node* prev=NULL;

    if(head->data==el){
        head=head->next;
        delete temp;
        return head;
    }
    while(temp){
        if(temp->data==el){
            prev->next=temp->next;
            delete temp;
            break;
        }

        prev=temp;
        temp=temp->next;
    }

    return head;
}

int main(){
    vector<int>v={1,2,3,4,5,6};
    Node* head=convertArr2LL(v);
    
    cout<<"Linked List is :";
    print(head);
    cout<<"\n";
    // head=removesHead(head);
    // cout<<"After removing the head element Linked List is :";
    // print(head);cout<<endl;

    // removesTail(head);
    // cout<<"After removing the tail element Linked List is :";
    // print(head);cout<<endl;

    // head=deleteKthNode(head,2);
    // print(head);cout<<endl;

    head=removeEl(head,5);
    print(head);cout<<endl;

    // 19. Remove Nth Node From End of List
    return 0;
}