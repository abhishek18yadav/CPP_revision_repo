#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

    TreeNode *f(vector<int> &nums, int left, int right)
    {
        if (right < left)
            return NULL;
        int mid = left + (right - left) / 2;
        TreeNode *Hd = new TreeNode(nums[mid]);
        Hd->left = f(nums, left, mid - 1);
        Hd->right = f(nums, mid + 1, right);
        return Hd;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return f(nums, 0, nums.size() - 1);
    }
    void display(TreeNode* node)
    {
        if (node == NULL)
            return;

        string str = "";

        str += node->left == NULL ? "." : to_string(node->left->val);
        str += " <- " + to_string(node->val) + " -> ";
        str += node->right == NULL ? "." : to_string(node->right->val);

        cout << str << endl;

        display(node->left);
        display(node->right);
    }
    int main()
    {
        vector<int> nums = {-10, -3, 0, 5, 9};
        TreeNode *root = sortedArrayToBST(nums);
        // The tree can be further processed or printed as needed.
        // lets print it;
        display(root);
        return 0;
    }