#include<bits/stdc++.h>
using namespace std;

class TreeNode{

    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val){
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};
        TreeNode* CreateTree(vector<int> &arr){
            TreeNode *root = new TreeNode(arr[0]);
            queue<TreeNode *> que;
            que.push(root);
            int i = 1, j = 2;

            while(!que.empty()and i<arr.size() and j<arr.size()){
                TreeNode *temp = que.front();
                que.pop();
                if(i<arr.size()){
                    if(arr[i]!= INT_MIN){
                        temp->left = new TreeNode(arr[i]);
                        que.push(temp->left);
                    }else
                        temp->left = NULL;
                }
                if(j<arr.size()){
                    if(arr[j]!= INT_MIN){
                        temp->right = new TreeNode(arr[j]);
                        que.push(temp->right);
                    }else
                        temp->right = NULL;
                }
                i += 2;
                j += 2;
            }
            return root;
        }
        void display(TreeNode* root){
            if(root==NULL){
                return;
            }
            cout << root->val << endl;
            display(root->left);
            display(root->right);   

        }
        bool isMirror(TreeNode *n1, TreeNode *n2)
        {
            if (n1 == NULL and n2 == NULL)
                return true;
            if (n1 == NULL || n2 == NULL)
                return false;

            return (n1->val == n2->val) ? isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left) : false;
        }
        bool isSymmetric(TreeNode *root)
        {
            return isMirror(root->left, root->right);
        }


int main(){
    vector<int> arr = {1,2,2,3,4,4,3};
    TreeNode *root = CreateTree(arr);
    // display(root);
    // cout << endl;
    cout << isSymmetric(root) << endl;
    return 0;
}

