/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    
    pair<int,bool> isSumTreeFast(Node* root){
        if(root == NULL){
            pair<int,bool> p = make_pair(0,1);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL){
            return {root->data, 1};
        }
        
        pair<int,bool> left = isSumTreeFast(root->left);
        pair<int,bool> right = isSumTreeFast(root->right);
        
        pair<int,bool> ans;
        ans.first = left.first + right.first + root->data;
        ans.second = ((left.first+right.first) == root->data) && left.second && right.second;
        
        return ans;
    }
    bool isSumTree(Node* root) {
        return isSumTreeFast(root).second;
    }
};