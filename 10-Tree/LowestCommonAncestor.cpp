#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

    Node *lca(Node *root, int v1, int v2)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->data > v1 && root->data > v2)
        {
            return lca(root->left, v1, v2);
        }
        if (root->data < v1 && root->data < v2)
        {
            return lca(root->right, v1, v2);
        }

        return root;
    }

}; //End of Solution

int main()
{
    // 1 2 5 3 6 4
    Node *root = new Node(1);
    Solution s;
    s.insert(root, 2);
    s.insert(root, 5);
    s.insert(root, 3);
    s.insert(root, 6);
    s.insert(root, 4);
    s.levelOrder(root);
    return 0;
}