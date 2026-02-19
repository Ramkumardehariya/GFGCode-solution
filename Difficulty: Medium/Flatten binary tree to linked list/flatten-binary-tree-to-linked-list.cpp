// User function Template for C++

class Solution {
  public:
  
    Node* findPred(Node* root){
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    }
    void flatten(Node *root) {
        
        Node* curr = root;
        
        while(curr != NULL){
            
            if(curr->left == NULL){
                curr = curr->right;
            }
            else{
                Node* pred = findPred(curr->left);
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                curr = curr->right;
            }
        }
        
    }
};