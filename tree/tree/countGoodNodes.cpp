
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <limits.h>
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
int f(TreeNode *root, int maxval)
{
    if (root == NULL)
        return 0;
    int count = 0;
    if(root->val >= maxval)
    {
        maxval = root->val;
        count+=f(root->left, maxval)+f(root->right, maxval)+1;
    }else{
        count+=f(root->left, maxval)+f(root->right, maxval);
    }
    return count;

}
int goodNodes(TreeNode *root)
{
    return f(root, INT_MIN);
}
int main()
{
    vector<int> vals{3, 1, 4, 3, INT_MIN, 1, 5};
    TreeNode *ans = construct(vals);
    cout << goodNodes(ans) << endl;
    return 0;
}