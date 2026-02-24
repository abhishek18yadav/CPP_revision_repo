#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    vector<int> ans;
    void f(TreeNode *root, int val)
    {
        if (!root)
            return;
        val = val * 10 + root->val;
        if (!root->left and !root->right)
        {
            ans.push_back(val);
            val /= 10;
            return;
        }
        if (root->left)
        {
            f(root->left, val);
        }
        if (root->right)
            f(root->right, val);
        val /= 10;
        return;
    }
    int sumNumbers(TreeNode *root)
    {
        int val = 0;
        f(root, val);
        val = 0;
        for (auto ele : ans)
            val += ele;
        return val;
    }
 int main(){

        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(0);
        root->right = new TreeNode(1);
        root->left->left = new TreeNode(0);
        root->left->right = new TreeNode(1);
        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(1);
        cout<<sumNumbers(root);
        return 0;
 }