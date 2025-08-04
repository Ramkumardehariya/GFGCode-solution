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
    int solve(Node* node){
        
    }
    
    int height(Node* node) {
        if((node == NULL) || (node->left == NULL && node->right == NULL)){
            return 0;
        }
        
        int left = height(node->left);
        int right = height(node->right);
        
        return max(left, right)+1;;
    }
};