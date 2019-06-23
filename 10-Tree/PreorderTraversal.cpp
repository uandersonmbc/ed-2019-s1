#include <bits/stdc++.h>

using namespace std;

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

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
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

    void preOrder(Node *root) {
        if(root == nullptr){
            return;
        }
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
        return;
    }

}; //End of Solution

int main(){
    // 1 2 5 3 6 4
    Node * root = new Node(1);
    Solution s;
    s.insert(root, 2);
    s.insert(root, 5);
    s.insert(root, 3);
    s.insert(root, 6);
    s.insert(root, 4);
    s.preOrder(root);   
    return 0;
}