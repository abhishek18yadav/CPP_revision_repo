#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<limits.h>
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
int main(){
    vector<int>vals{2,5,4,3,6,8,INT_MIN,INT_MIN,23,INT_MIN,1,56};
    TreeNode* ans = construct(vals);
    cout<<ans->value<<endl;
    return 0;
}