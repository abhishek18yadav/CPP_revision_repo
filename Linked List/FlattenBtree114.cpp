#include<bits/stdc++.h>
using namespace std;
 /// for correct answer see in algoZenith folder
struct TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};
class LinkedList{
    public:
        Node *head;
        LinkedList(){
            this->head = NULL;
        }
};
void add(int val , LinkedList &list){
    if(list.head == NULL){
        list.head = new Node(val);
        return;
    }
    Node *temp = list.head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new Node(val);
    temp = temp->next;
}
void display(TreeNode* h , LinkedList &l1){
    if(!h)
        return;
    add(h->val, l1);
    display(h->left ,l1);
    display(h->right ,l1);
}
TreeNode* generateTree(vector<int> &root)
{
    if(root.size()==0)
        return NULL;
    TreeNode *head = new TreeNode(root[0]);
    queue<TreeNode *> q;
    q.push(head);
    int i = 1;
    int j = 2;
    int sze = root.size();
    while(!q.empty() and i< sze and j<sze){
        TreeNode *temp = q.front();
        q.pop();
        TreeNode* leftNode = NULL;
        TreeNode* rightNode = NULL;
        if(root[i]){
            leftNode = new TreeNode(root[i]);
            temp->left = leftNode;
            q.push(leftNode);
        } else
            temp->left = NULL;
        if(root[j]){
            rightNode = new TreeNode(root[j]);
            temp->right = rightNode;
            q.push(rightNode);
        }else
            temp->right = NULL;
        i += 2;
        j += 2;
    }
    return head;
}

void displayll(LinkedList &ll){
    Node *temp = ll.head;
    while(temp){
        cout << "hello";
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void flatten(TreeNode *root)
{
    LinkedList l1;
    cout << "checj1";
    display(root , l1);
    cout << l1.head->data << endl;
    displayll(l1);
}

int main(){
    vector<int>root = {1,2,5,3,4,NULL,6};
    TreeNode *head = generateTree(root);
    flatten(head);
    return 0;  
}
