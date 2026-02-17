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
    void leftData(Node* root, vector<int> &ans){
        if(root == NULL || root->left == NULL && root->right == NULL){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            leftData(root->left, ans);
        }
        else{
            leftData(root->right, ans);
        }
    }
    void allLeafNode(Node* root, vector<int> &ans){
        if(root== NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        allLeafNode(root->left, ans);
        allLeafNode(root->right, ans);
    }
    
    void rightData(Node* root, vector<int> &ans){
        if(root == NULL || root->left == NULL && root->right == NULL){
            return;
        }
        if(root->right){
            rightData(root->right, ans);
        }
        else{
            rightData(root->left, ans);
        }
        ans.push_back(root->data);
    }
    
    
    vector<int> boundaryTraversal(Node *root) {
    
        vector<int> ans;
        ans.push_back(root->data);
        leftData(root->left, ans);
        allLeafNode(root->left, ans);
        allLeafNode(root->right, ans);
        rightData(root->right, ans);
        
        return ans;
    }
};