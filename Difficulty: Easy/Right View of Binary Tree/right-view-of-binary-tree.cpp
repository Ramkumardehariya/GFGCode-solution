/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution {
  public:
  
    void solve(Node* root, vector<int> &ans, int lvl){
        if(root == NULL){
            return;
        }
        
        if(lvl == ans.size()){
            ans.push_back(root->data);
        }
        
        solve(root->right, ans, lvl+1);
        solve(root->left, ans, lvl+1);
    }
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
        // Your Code here
        vector<int> ans;
        
        solve(root, ans, 0);
        
        return ans;
        
    }
};