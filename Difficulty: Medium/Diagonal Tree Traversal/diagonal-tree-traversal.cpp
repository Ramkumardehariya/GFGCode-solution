/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        queue<Node*> q;
        vector<int> ans;
        
        q.push(root);
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            while(curr){
                ans.push_back(curr->data);
                if(curr->left){
                    q.push(curr->left);
                }
                curr = curr->right;
            }
        }
        return ans;
    }
};