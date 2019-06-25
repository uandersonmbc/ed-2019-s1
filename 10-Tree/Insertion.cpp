#include <iostream>
#include <cstddef>

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
    void preOrder(Node *root)
    {

        if (root == NULL)
            return;

        std::cout << root->data << " ";

        preOrder(root->left);
        preOrder(root->right);
    }

    /* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node *insert(Node *root, int data)
    {
        if (root == nullptr)
        {
            root = new Node(data);
        }
        if (root->data > data)
        {
            root->left = insert(root->left, data);
        }
        if (root->data < data)
        {
            root->right = insert(root->right, data);
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