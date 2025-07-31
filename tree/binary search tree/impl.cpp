#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int val){
        this->val= val;
        this->left=NULL;
        this->right=NULL;
    }
};
    node* insertFun(node* root,int value){
        node* temp = new node(value);

        if(root == NULL){
            return temp;
        }
        if(temp->val < root->val){
            root->left = insertFun(root->left,value);
        }
        else{
            root->right = insertFun(root->right , value);
        }
        return root;
    }
    node* findSuccessor(node* root){
        if(root->left ==NULL and root->right ==NULL){
            return root;
        }
        if(root->left)findSuccessor(root->left);
        else findSuccessor(root->right);
    }
    
    node* deleteFun(node* root , int value){
        node* temp = new node(value);
        // if(value == NULL)return root;


        if(temp-> val < root->val){
            root->left =deleteFun(root-> left , value);
        }
        else if(temp-> val > root->val){
            root->right= deleteFun(root-> right , value);
        }
        else{
            // if it is right derivative
            if(root->left ==NULL ){
                return root->right;
            }
            else if(root->right == NULL)return root->left;

            else{
                node* temp2 = root;
                node* successor = findSuccessor(temp2->right);
                temp2 = root;
                root->val = successor->val;
                root->right = deleteFun(temp2->right , successor->val);
            }
        }
        return root;
    }
    void traversal(node* root){
        if(root==NULL)return;
        cout<<root->val<<"-";
        traversal(root->left);
        traversal(root->right);
    }
    

    int main(){
        node* root= new node(10);
        insertFun(root,20);
        insertFun(root,30);
        insertFun(root,2);
        insertFun(root,220);
        insertFun(root,1);
        insertFun(root,23);
        cout<<deleteFun(root,10)->val<<endl;
        traversal(root);
        return 0;
    }
