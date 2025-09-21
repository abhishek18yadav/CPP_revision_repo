#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        this->val = value;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *construct(vector<int> &vals)
{
    TreeNode *root = new TreeNode(vals[0]);

    int leftptr = 1, rightptr = 2;
    queue<TreeNode *> tre;
    tre.push(root);
    while (!tre.empty() && leftptr < vals.size() && rightptr < vals.size())
    {
        TreeNode *temp = tre.front();
        tre.pop();
        if (vals[leftptr] != INT_MIN)
        {
            temp->left = new TreeNode(vals[leftptr]);
            tre.push(temp->left);
        }
        else
            temp->left = NULL;

        if (vals[rightptr] != INT_MIN)
        {
            temp->right = new TreeNode(vals[rightptr]);
            tre.push(temp->right);
        }
        else
            temp->right = NULL;
        leftptr += 2;
        rightptr += 2;
    }
    return root;
}
int maxZigZag;
void f(TreeNode *root,int sizes, bool rightTurn)
{
    if (!root)
    {
        return;
    }
    maxZigZag = max(maxZigZag, sizes);
    if (!rightTurn and root->right)
    {
        f(root->right, sizes+1, true);
        f(root->right, 0, false );
    }
    if (rightTurn and root->left)
    {
        f(root->left, sizes+1, false);
        f(root->left, 0, true);
    }
    
    return ;
}
int longestZigZag(TreeNode *root)
{
    maxZigZag = 0;
    int sizes = 0;
     f(root, sizes, false);
     f(root, sizes, true);
     return maxZigZag;
}
int main()
{
    //vector<int> vals{1, INT_MIN, 1, 1, 1, INT_MIN, INT_MIN, 1, 1, INT_MIN, 1, INT_MIN, INT_MIN, INT_MIN, 1};
    vector<int> vals{6, 9, 7, 3, INT_MIN, 2, 8, 5, 8, 9, 7, 3, 9, 9, 4, 2, 10, INT_MIN, 5, 4, 3, 10, 10, 9, 4, 1, 2, INT_MIN, INT_MIN, 6, 5, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 9, INT_MIN, 9, 6, 5, INT_MIN, 5, INT_MIN, INT_MIN, 7, 7, 4, INT_MIN, 1, INT_MIN, INT_MIN, 3, 7, INT_MIN, 9, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 9, 9, INT_MIN, INT_MIN, INT_MIN, 7, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 6, 8, 7, INT_MIN, INT_MIN, INT_MIN, 3, 10, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 1, INT_MIN, 1, 2};
    TreeNode *ans = construct(vals);
    int res = longestZigZag(ans);
    cout << res << endl;
    return 0;
}