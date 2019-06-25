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

    void top(Node *root, map<int, pair<int, int>> &topView, int nivel, int altura){
        if (root == nullptr) return;
        if (
            topView.find(altura) == topView.end() || 
            nivel < topView[altura].second
        ) 
            topView[altura] = {root->data, nivel};
        
        top(root->left, topView, nivel + 1, altura - 1);
        top(root->right, topView, nivel + 1, altura + 1);
    }

    void topView(Node *root){
        map<int, pair<int, int>> topView;
        top(root, topView, 0, 0);
        for (auto elem : topView) cout << elem.second.first << " ";
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
    s.topView(root);
    return 0;
}