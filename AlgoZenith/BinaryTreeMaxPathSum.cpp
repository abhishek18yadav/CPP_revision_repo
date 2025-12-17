#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}  TreeNode(int x) : val(x), left(nullptr), right(nullptr){} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
    int f(TreeNode *root, int &ans)
    {
        if (!root)
            return 0;
        int left = f(root->left, ans);
        int right = f(root->right, ans);
        // maxsum can be sum of l+r+root
        int cond1 = left + right + root->val;
        // maxsum can be leftside includeing root or rightside includeing root
        int cond2 = max(left, right) + root->val;
        // maxsum can be root
        int cond3 = root->val;
        ans = max({ans, cond1, cond2, cond3});

        return max(cond2, cond3); // beacause these two condotion only have hpe to go up the root and explore more path, otherwise condition1 tahes bent shape
    }
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        f(root, ans);
        return ans;
    }

    int main()
    {
        TreeNode *root = new TreeNode(-10);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        cout << maxPathSum(root) << endl;
        return 0;
    }