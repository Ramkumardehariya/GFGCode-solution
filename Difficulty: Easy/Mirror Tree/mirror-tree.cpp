/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void mirror(Node* node) {
        if(node == NULL || (node->left == NULL && node->right == NULL)){
            return;
        }
        
        mirror(node->left);
        mirror(node->right);
        
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};