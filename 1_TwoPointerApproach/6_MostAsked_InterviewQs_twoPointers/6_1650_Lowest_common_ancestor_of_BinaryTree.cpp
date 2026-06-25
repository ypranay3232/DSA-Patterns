// 1650 : Lowest common Ancestor (parent) of a binary tree III. Given two nodes of binary tree p,q return their lowest common ancestor.
// In standard LCA problems we start at root and look to bottom but here we dont get root rather node is defined as :
/*
class node{
public:
int val;
Node* right;
NOde* left;
Node* parent;//bcz we have root we dont care about entire tree, we can start at p,q
}
*/

#include <iostream>
using namespace std;

// create the structure of node
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *parent;

    Node(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

class solution
{
public:
    Node *lowestCommonAncestor(Node *p, Node *q)
    {
        // we create two pointers a,b
        Node *a = p;
        Node *b = q;

        // we run the loop until two pointers collide (come together) to a parent(Ancestor)
        while (a != b)
        {
            // we have two nodes and two pointers. move 'a' to top, if it hits root redirect it to start again from node b
            a = (a == nullptr) ? q : a->parent;
            b = (b == nullptr) ? p : b->parent;
        }
        // when a == b both are pointing to a common parent so return a.
        return a;
    }
};

int main()
{
    // Manually constructing a small tree for testing:
    //       3
    //      / \
    //     5   1
    //    /
    //   6

    Node *root = new Node(3);
    Node *node5 = new Node(5);
    Node *node1 = new Node(1);
    Node *node6 = new Node(6);
    // Set up children
    root->left = node5;
    root->right = node1;
    node5->left = node6;

    // Set up parent pointers (Crucial for LeetCode 1650!)
    root->parent = nullptr;
    node5->parent = root;
    node1->parent = root;
    node6->parent = node5;

    solution solver;
    // Test Case : LCA of 6 and 1 should be 3
    Node *lca1 = solver.lowestCommonAncestor(node6, node1);
    std::cout << "LCA of 6 and 1 is: " << (lca1 ? lca1->val : -1) << " (Expected: 3)\n";

     // Clean up dynamic memory
    delete node6;
    delete node1;
    delete node5;
    delete root;
    
    return 0;

}