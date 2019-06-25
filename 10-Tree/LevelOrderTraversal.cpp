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
    /*
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

    void levelOrder(Node *root)
    {
        int nivel = nivelTree(root);
        for (int i = 0; i < nivel; i++)
        {
            show(root, i);
        }
    }

    void show(Node *root, int nivel)
    {
        if (root == nullptr)
            return;
        if (nivel == 0)
        {
            cout << root->data << " ";
        }
        else if (nivel > 0)
        {
            show(root->left, nivel - 1);
            show(root->right, nivel - 1);
        }
    }

    int nivelTree(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int nivelL = nivelTree(root->left);
        int nivelR = nivelTree(root->right);
        if (nivelL > nivelR)
        {
            return (nivelL + 1);
        }
        else
        {
            return (nivelR + 1);
        }
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