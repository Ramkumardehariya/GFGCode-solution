/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    
    pair<int,int> diameterFast(Node *root){
        if(root == NULL){
            return {0,0};
        }
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        
        int op3 = left.second + right.second;
        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second)+1;
        
        return ans;
    }
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};