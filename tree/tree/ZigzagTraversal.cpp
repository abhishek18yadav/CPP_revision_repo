#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        this->value=value;
        this->left=NULL;
        this->right=NULL;
    }
};

TreeNode* construct(vector<int>&vals){
    TreeNode* root = new TreeNode(vals[0]);

    int leftptr = 1, rightptr=2;
    queue<TreeNode*>tre;
    tre.push(root);
    while(!tre.empty() && leftptr<vals.size() && rightptr<vals.size()){
        TreeNode* temp = tre.front();
        tre.pop();
        if(vals[leftptr]!= INT_MIN){
            temp->left= new TreeNode(vals[leftptr]);
            tre.push(temp->left);
        }
        else temp->left= NULL;
        
        if(vals[rightptr]!= INT_MIN){
            temp->right= new TreeNode(vals[rightptr]);
            tre.push(temp->right);
        }
        else temp->right= NULL;
        leftptr+=2;
        rightptr+=2;
    }
    return root;
}

int levelOfTree(TreeNode* root){
    if(!root)return 0;
    return 1+ max(levelOfTree(root->left), levelOfTree(root->right));
}
void traverse(TreeNode* root){
    if(!root)return;
    cout<<root->value<<" ";
    traverse(root->left);
    traverse(root->right);
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*>que;
    que.push(root);
    que.push(NULL);
    vector<vector<int>>ans;
    vector<int>res;
    int level = levelOfTree(root);
    while(!que.empty() && level>0){
        TreeNode* temp = que.front();
        que.pop();
        
        if(!temp){
            if(level%2 != 0){
                reverse(res.begin(),res.end());
            }
            ans.push_back(res);
            res.clear();
            que.push(NULL);
            level--;
        }else{
            res.push_back(temp->value);
            if(temp->left)que.push(temp->left);
            if(temp->right)que.push(temp->right);
        }
    }
    return ans;
}
int main(){
    vector<int>vals{1,2,3};
    TreeNode* root = construct(vals);
    // traverse(root);
    vector<vector<int>>result = zigzagLevelOrder(root);
    for(auto ele : result){
        for(auto val : ele){
            cout<<val<<",";
        }
        cout<<endl;
    }
    return 0;
}