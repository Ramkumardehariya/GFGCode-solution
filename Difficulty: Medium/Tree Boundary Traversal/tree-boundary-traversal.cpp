/*
// Tree Node
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
  
    void leftPart(Node* root, vector<int> &ans){
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            leftPart(root->left, ans);
        }
        else{
            leftPart(root->right, ans);
        }
    }
    
    void leafNode(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        leafNode(root->left, ans);
        leafNode(root->right, ans);
    }
    
    void rightPart(Node* root, vector<int> &ans){
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return;
        }
        
        if(root->right){
            rightPart(root->right, ans);
        }
        else{
            rightPart(root->left, ans);
        }
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        ans.push_back(root->data);
        
        leftPart(root->left, ans);
        
        leafNode(root->left, ans);
        leafNode(root->right, ans);
        
        rightPart(root->right, ans);
        
        return ans;
    }
};