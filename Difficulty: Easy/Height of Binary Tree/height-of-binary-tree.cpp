/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int height(Node* root) {
        
        if(root == NULL || root->left == NULL && root->right == NULL){
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        return 1+max(left,right);
    }
};