/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    pair<int,bool> isBlanacedFast(Node* root){
        if(root == NULL){
            pair<int,bool> p = make_pair(0,1);
            return p;
        }
        
        pair<int,bool> left = isBlanacedFast(root->left);
        pair<int,bool> right = isBlanacedFast(root->right);
        
        pair<int,bool> ans;
        ans.first = max(left.first,right.first)+1;
        ans.second = (abs(left.first-right.first) <= 1) && left.second && right.second;
        
        return ans;
    }
    bool isBalanced(Node* root) {
        return isBlanacedFast(root).second;
    }
};