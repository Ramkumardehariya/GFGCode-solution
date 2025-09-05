/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    pair<int,bool> solve(Node* root){
        if(root == NULL){
            return {0,true};
        }
        if(root->left == NULL && root->right == NULL){
            return {root->data, true};
        }
        
        pair<int,bool> left = solve(root->left);
        pair<int,bool> right = solve(root->right);
        
        pair<int,bool> ans;
        bool check = ((left.first + right.first) == root->data) && left.second && right.second;
        ans.second = check;
        ans.first = left.first+right.first+root->data;
        
        return ans;
    }
    bool isSumTree(Node* root) {
        return solve(root).second;
    }
};