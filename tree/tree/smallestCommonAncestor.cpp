#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <limits.h>
#include <unordered_map>
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
void level(TreeNode* root, unordered_map<int, int> &mp){
    queue<TreeNode*> q;
    q.push(root);
    int level = 1;
    int leftptr=1, rightptr=2;
    q.push(NULL);
    while(!q.empty() ){
        TreeNode* temp = q.front();
        if(temp==NULL){
            level++;
            q.pop();
            if(!q.empty())
                q.push(NULL);
            continue;
        }
        mp[temp->val] = level;
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

TreeNode* reqParent(TreeNode* root , int req_level , int curr_level, TreeNode* minval, int upper_levelval){
    if(!root)return NULL;
    if (root->val == upper_levelval )
    {
        int minnodeVal = min(root->val, minval->val);
        return new TreeNode(minnodeVal);
    }
    int req_minval = min(root->val , minval->val);
    TreeNode *left = reqParent(root->left, req_level, curr_level + 1, new TreeNode(req_minval), upper_levelval);
    TreeNode *right = reqParent(root->right, req_level, curr_level + 1, new TreeNode(req_minval), upper_levelval);
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    unordered_map<int, int> mp;
    level(root, mp);
    int p_level = mp[p->val];
    int q_level = mp[q->val];
    int req_level = min(p_level, q_level);
    //cout<<p_level<<" "<<q_level<<endl;
    int upper_levelval=0;
    if(p_level==req_level){
        upper_levelval = p->val;
    }if( q_level!=p_level and  q_level==req_level ){
        upper_levelval = q->val;
    }
    cout<<req_level<<" "<<upper_levelval<<endl;
    return reqParent(root, req_level, 1, root, upper_levelval);
}
int main()
{
    vector<int> vals{3, 5, 1, 6, 2, 0, 8, INT_MIN, INT_MIN, 7, 4};
    TreeNode *ans = construct(vals);
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(1);
    TreeNode* res = lowestCommonAncestor(ans, p, q);
    cout<<res->val<<endl;
    return 0;
}