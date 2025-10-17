/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
  void traverse( Node* nd , int &curr){
      if(nd == NULL)return;
      traverse(nd->right,curr);
      int temp = nd->data;
      nd->data = curr;
      curr+=temp;
      traverse(nd->left,curr);
  }
    void transformTree(Node *root) {
        // code here
        int curr = 0;
        traverse(root ,curr);
        return;
    }
};