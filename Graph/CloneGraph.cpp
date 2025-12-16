#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};



    void f(Node *rl_node, unordered_map<Node *, Node *> &mp)
    {
        vector<Node *> n;
        for (auto nbr : rl_node->neighbors)
        {
            if (mp.find(nbr) == mp.end())
            {
                Node *temp = new Node(nbr->val);
                mp[nbr] = temp;
                n.push_back(temp);
                f(nbr, mp);
            }
            else
            {
                n.push_back(mp[nbr]);
            }
        }
        mp[rl_node]->neighbors = n;
        return;
    }
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        unordered_map<Node *, Node *> mp;
        Node *newNode = new Node(node->val);
        mp[node] = newNode;
        f(node, mp);
        return newNode;
    }
    void display(Node* node, unordered_set<int>& visited = *(new unordered_set<int>())) {
        if (!node || visited.count(node->val)) return;
        visited.insert(node->val);
        cout << "Node " << node->val << " neighbors: ";
        for (auto neighbor : node->neighbors) {
            cout << neighbor->val << " ";
        }
        cout << endl;
        for (auto neighbor : node->neighbors) {
            display(neighbor, visited);
        }

    }
    int main(){
        Node* node1 = new Node(1);
        Node* node2 = new Node(2);
        Node* node3 = new Node(3);
        Node* node4 = new Node(4);
        node1->neighbors.push_back(node2);
        node1->neighbors.push_back(node4);
        node2->neighbors.push_back(node1);
        node2->neighbors.push_back(node3);
        node3->neighbors.push_back(node2);
        node3->neighbors.push_back(node4);
        node4->neighbors.push_back(node1);
        node4->neighbors.push_back(node3);

        Node* cloned_N =   cloneGraph(node1);
        display(cloned_N);
        return 0;
    }