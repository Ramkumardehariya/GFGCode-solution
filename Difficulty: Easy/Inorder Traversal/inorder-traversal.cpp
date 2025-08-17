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
  
    Node* find(Node* curr){
        Node* temp = curr;
        
        temp = temp->left;
        
        while(temp->right != NULL && temp->right != curr){
            temp = temp->right;
        }
        
        return temp;
    }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        
        Node* curr = root;
        
        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else{
                Node* pred = find(curr);
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    ans.push_back(curr->data);
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};