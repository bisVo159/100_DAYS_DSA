#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildTree(Node* root){
     cout<<"Enter the data"<<endl;
     int data;
     cin>>data;
     root = new Node(data);
     if(data==-1){
        return NULL;
     }
     cout<<"Enter data for inserting in left of "<<data<<endl;
     root->left=buildTree(root->left);
     cout<<"Enter data for inserting in right of "<<data<<endl;
     root->right=buildTree(root->right);
     return root;
}

void levelOrderTraversal(Node* root){
      queue<Node*>q;
      q.push(root);
      q.push(NULL);

      while(!q.empty()){
        Node* temp=q.front();
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

    void traverse(Node* root,unordered_map<Node*,Node*>&parent){
        if(root==NULL){
            return;
        }
        
        if(root->left!=NULL){
            parent[root->left]=root;
            traverse(root->left,parent);
        }
       
       if(root->right!=NULL){
            parent[root->right]=root;
            traverse(root->right,parent);
       }
    }
    
    Node* search(Node* root,int& target){
        if(root==NULL)
        return NULL;
        
        if(root->data==target)
        return root;
        
        Node* leftAns=search(root->left,target);
        if(leftAns)
        return leftAns;
        
        return search(root->right,target);
    }
    
    void findAns(Node* root,int k,unordered_map<Node*,Node*>&parent,int &ans,unordered_map<Node*,bool>&visited){
        if(root==NULL||k<0)
        return;
        
        ans=ans+root->data;
        visited[root]=1;
        
        if(!visited[root->left])
        findAns(root->left,k-1,parent,ans,visited);
        if(!visited[root->right])
        findAns(root->right,k-1,parent,ans,visited);
        if(!visited[parent[root]])
        findAns(parent[root],k-1,parent,ans,visited);
    }

int main(){
    // Sum of nodes within K distance from target -> https://practice.geeksforgeeks.org/problems/sum-of-nodes-within-k-distance-from-target--170637/1
       Node* root=buildTree(NULL);
       int target=5,k=3;

        unordered_map<Node*,Node*>parent;
        parent[root]=NULL;
        traverse(root,parent);
        
        Node* targetNode=search(root,target);
        
        int ans=0;
        unordered_map<Node*,bool>visited;
        
        findAns(targetNode,k,parent,ans,visited);

        cout<<"Sum of nodes within "<<k<<"  distance from "<<target<<" = "<<ans<<endl;

        // 863. All Nodes Distance K in Binary Tree

    return 0;
}