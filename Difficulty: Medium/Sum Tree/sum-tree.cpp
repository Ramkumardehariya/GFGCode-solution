/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
  
    pair<bool,int> solve(Node* root){
        if(root == NULL){
            return {true,0};
        }
        if(root->left == NULL && root->right == NULL){
            return {true,root->data};
        }
        
        pair<bool,int> left = solve(root->left);
        pair<bool,int> right =solve(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool cond = root->data == left.second+right.second;
        
        pair<bool,int> ans;
        
        if(leftAns && rightAns && cond){
            ans.first = true;
            ans.second = 2*root->data;
        }
        else{
            ans.first = false;
            ans.second = root->data + left.second + right.second;
        }
        return ans;
    }
    bool isSumTree(Node* root) {
        return solve(root).first;
    }
};