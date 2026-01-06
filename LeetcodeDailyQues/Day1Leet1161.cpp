#include<bits/stdc++.h>
using namespace std;


class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        this->value = value;
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
    int maxsum = INT_MIN;
    int sum = 0;
    queue<TreeNode *> tre;
    tre.push(root);
    tre.push(NULL);
    sum+=root->value;
    int level = 1;
    unordered_map<int,vector<int>> levelsum;
    while(!tre.empty()){
        TreeNode *temp = tre.front();
        tre.pop();
        if(temp == NULL){
            maxsum = max(maxsum, sum);
            cout<<"Level "<<level<<" Sum "<<sum<<endl;
            levelsum[sum].push_back(level);
            sum = 0;
            if(!tre.empty()){
                tre.push(NULL);
                level++;
                continue;
            }
            else
                break;
        }
        sum += temp->value;
        TreeNode *left = temp->left;
        TreeNode *right = temp->right;
        if (left)
            tre.push(left);
        if(right)
            tre.push(right);
        
    }
    // if there is case in which multiple levels have same sum then return the smallest level
    sort(levelsum[maxsum].begin(),levelsum[maxsum].end());
    return levelsum[maxsum][0];
}
int main()
{
    vector<int> vals{-1, -1, 1, 0, 0};
    TreeNode *ans = construct(vals);
    cout << maxLevelSum(ans) << endl;
    return 0;
}