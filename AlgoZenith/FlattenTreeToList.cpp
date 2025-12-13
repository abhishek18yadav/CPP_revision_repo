#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    /* data */
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(){
        left = NULL;
        right = NULL;
    }
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

void flatten(TreeNode *root)
{
    if (!root)
        return;
    if (root->left)
    {
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        TreeNode *temp = left;

        while (temp->right)
            temp = temp->right;

        root->right = left;
        temp->right = right;
        root->left = NULL;
    }
    flatten(root->right);
}
void display(TreeNode* root){
    TreeNode* curr = root;
    while(curr){
        cout<<curr->val<<" ";
        curr = curr->right;
    }
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    flatten(root);
    display(root);
    return 0;
}