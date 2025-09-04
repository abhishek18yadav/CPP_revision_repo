#include <bits/stdc++.h>
using namespace std;

class TreeNode
{

public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// start and end helps here to make partition into left and right
TreeNode *f(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &mp, int &idxOfInorder, int start, int end)
{
    if (start > end)
        return NULL;
    int rootVal = postorder[idxOfInorder];
    idxOfInorder--;
    int posInInorder = mp[rootVal];
    TreeNode *root = new TreeNode(rootVal);
    root->right = f(inorder, postorder, mp, idxOfInorder, posInInorder + 1, end);
    root->left = f(inorder, postorder, mp, idxOfInorder, start, posInInorder - 1);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{

    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    int end = postorder.size() - 1;
    return f(inorder, postorder, mp, end, 0, inorder.size() - 1);
}

int main(){
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* root = buildTree(inorder, postorder);
    cout<<root->val<<endl; // Output the root value to verify
    return 0;
}