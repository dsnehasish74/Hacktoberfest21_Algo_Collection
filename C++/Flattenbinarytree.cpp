#include<iostream>
using namespace std;

//structure for node
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

//flatten function which takes root of the binary tree 
void flatten(node* root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL){
        flatten(root->left);
        node* temp=root->right; 
        root->right=root->left;  //store root->left(left most node) in root->right
        root->left=NULL;        //make left part of node NULL
        node* t=root->right;   //find rightmost node of the root->right
        while(t->right!=NULL){
            t=t->right;
        }
        t->right=temp;    //temp stores initial right subtree of root
    }
    flatten(root->right);
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
  //building tree
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->left->left=new node(6);
    root->right->left=new node(7);
    root->right->right=new node(8);
    flatten(root);
  //Print inoreder of the flatten tree
    inorder(root);
    return 0;
}
