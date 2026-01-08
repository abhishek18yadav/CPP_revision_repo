#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {};
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};



    long long mod = 1000000007;
    long long sum(long long totalSum, long long &maxSum, TreeNode *root)
    {
        if (!root)
            return 0;
        long long leftSum = sum(totalSum, maxSum, root->left);
        long long rightSum = sum(totalSum, maxSum, root->right);
        long long subTreeSum = root->val + leftSum + rightSum;
        long long valueLeft = totalSum - subTreeSum;
        maxSum = max(maxSum, valueLeft * subTreeSum);
        return subTreeSum;
    }
    long long f(TreeNode *root)
    {
        if (!root)
            return 0;
        return root->val + f(root->left) + f(root->right);
    }
    int maxProduct(TreeNode *root)
    {
        long long TotalSum = f(root);
        long long maxSum = 0;
        long long ans = sum(TotalSum, maxSum, root);
        return maxSum % mod;
    }

    int main(){
        vector<int> arr = {1,2,3,4,5,6};
        TreeNode* root = new TreeNode(1);
        TreeNode* node1 = new TreeNode(2);
        TreeNode* node2 = new TreeNode(3);
        TreeNode* node3 = new TreeNode(4);
        TreeNode* node4 = new TreeNode(5);
        TreeNode* node5 = new TreeNode(6);
        root->left = node1;
        root->right = node2;
        node1->left = node3;
        node1->right = node4;
        node2->left = node5;
        cout<<maxProduct(root);
        return 0;
    }