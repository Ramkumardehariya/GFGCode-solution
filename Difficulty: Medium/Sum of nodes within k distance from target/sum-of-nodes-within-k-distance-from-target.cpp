/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution {
  public:
  
    void createParent(Node* root, unordered_map<Node*,Node*> &parent){
        if(root == NULL){
            return ;
        }
        
        if(root->left){
            parent[root->left] = root;
            createParent(root->left, parent);
        }
        
        if(root->right){
            parent[root->right] = root;
            createParent(root->right, parent);
        }
    }
    
    Node* search(Node* root, int target){
        if(root == NULL){
            return NULL;
        }
        
        if(root->data == target){
            return root;
        }
        
        Node* leftAns = search(root->left, target);
        if(leftAns != NULL){
            return leftAns;
        }
        Node* rightAns = search(root->right, target);
        if(rightAns != NULL){
            return rightAns;
        }
        return NULL;
    }
    
    
    void solve(Node* root, int k, unordered_map<Node*,Node*> &parent, int &ans, unordered_map<Node*,bool> &vis){
        if(root == NULL){
            return;
        }
        if(k < 0){
            return;
        }
        
        if(!vis[root]){
            ans += root->data;
            vis[root] = true;
            solve(root->left, k-1, parent, ans, vis);
            solve(root->right, k-1, parent, ans, vis);
            solve(parent[root], k-1, parent, ans, vis);
        }
    }
    
    
    int sum_at_distK(Node* root, int target, int k) {
        unordered_map<Node*,Node*> parent;
        parent[root] = NULL;
        
        createParent(root, parent);
        Node* node = search(root, target);
        unordered_map<Node*,bool> vis;
        
        int ans = 0;
        
        solve(node, k, parent, ans, vis);
        
        return ans;
    }
};
