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
int maxLevelSum(TreeNode *root)
{
    queue<TreeNode *> que;
    que.push(root);
    que.push(NULL);
    int level = 1;
    int sum = 0;
    unordered_map<int, int> mp;
    while (!que.empty())
    {
        TreeNode *temp = que.front();
        que.pop();
        
        if (temp == NULL)
        {
            mp[level] = sum;
            sum = 0;
            level++;
            if (!que.empty())
            {
                que.push(NULL);
            }
            continue;
        }
        sum += temp->val;
        if (temp->left)
            que.push(temp->left);
        if (temp->right)
            que.push(temp->right);
    }
    for(auto ele : mp){
        cout << ele.first << " " << ele.second << endl;
        }
    int maxlvl = 0;
    int maxVal = 0;
    for (auto ele : mp)
    {
        int lvl = ele.first;
        int lvlval = ele.second;
        if (maxVal < lvlval)
        {
            maxlvl = lvl;
            maxVal = lvlval;
        }
    }
    vector<int> ans;
    for(auto ele : mp){
        if(ele.second == maxVal){
            ans.push_back(ele.first);
        }
    }
    sort(ans.begin(), ans.end());
    return ans[0];
}

int main()
{
    vector<int> vals{1, 1, 0, 7, -8, -7, 9};
    TreeNode *ans = construct(vals);
    cout << maxLevelSum(ans);
    return 0;
}