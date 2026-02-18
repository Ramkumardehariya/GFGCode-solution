/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* solve(Node* root, int n1, int n2){
        if(root == NULL){
            return NULL;
        }
        
        Node* left = solve(root->left, n1, n2);
        Node* right = solve(root->right, n1, n2);
        
        
        if(root->data == n1){
            return root;
        }
        else if(root->data == n2){
            return root;
        }
        else if(left != NULL && right != NULL){
            return root;
        }
        else if(left == NULL && right != NULL){
            return right;
        }
        else if(left != NULL && right  == NULL){
            return left;
        }
        else{
            return NULL;
        }
    }
    Node* lca(Node* root, int n1, int n2) {
        return solve(root, n1, n2);
    }
};