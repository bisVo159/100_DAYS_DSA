#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
     cout<<"Enter the data"<<endl;
     int data;
     cin>>data;
     root = new node(data);
     if(data==-1){
        return NULL;
     }
     cout<<"Enter data for inserting in left of "<<data<<endl;
     root->left=buildTree(root->left);
     cout<<"Enter data for inserting in right of "<<data<<endl;
     root->right=buildTree(root->right);
     return root;
}

void rightTraverse(node* root){
    if(root==NULL)
    return;

    rightTraverse(root->right);
    cout<<root->data<<" ";
    rightTraverse(root->right);
}

void levelOrderTraversal(node* root){
      queue<node*>q;
      q.push(root);
      q.push(NULL);

      while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL){//Old level traverse completed
            cout<<endl;
            if(!q.empty()) {     //queue still has some child nodes
                  q.push(NULL);
            }
        }

        else{
              cout<<temp->data<<" ";
            if(temp->left){
             q.push(temp->left);
        }

        if(temp->right){
             q.push(temp->right);
        }
        }
      }
}

void inorder(node* root){
    if(root==NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL)
    return;

   cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

// Symmetric tree
bool   checkMirror(node* root1,node* root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    if((root1==NULL&&root2!=NULL)||(root1!=NULL&&root2==NULL)){
        return false;
    }
    if(root1->data!=root2->data)
    return false;
    
        bool left_mirrored = checkMirror(root1->left , root2->right );
        bool right_mirrored = checkMirror(root1->right , root2->left );
        return (left_mirrored && right_mirrored);
}

int height(node* root){
    if(root==NULL)
    return 0;

    return 1+max(height(root->left),height(root->right));
}

int main(){
    // node* root=NULL;
    // root=buildTree(root);
    // 3 4 -1 -1 5 -1 6 -1 -1
    // rightTraverse(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // levelOrderTraversal(root);

    // inorder(root);
    // cout<<endl;
    // preorder(root);
    // cout<<endl;
    // postorder(root);


    // Mirror Tree Check
    node* root1=buildTree(NULL);
    // 1 3 -1 -1 2 5 -1 -1 4 -1 -1
    node* root2=buildTree(NULL);
    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1

    if(checkMirror(root1,root2)){
        cout<<"Mirror Tree"<<endl;
    }
    else{
        cout<<"Not Mirror Tree"<<endl;
    }


}