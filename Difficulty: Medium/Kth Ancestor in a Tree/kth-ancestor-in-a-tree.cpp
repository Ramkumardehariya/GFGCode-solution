/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
  public:
    int kthAncestor(Node *root, int k, int node) {
        unordered_map<int,int> mp;
        
        queue<Node*> q;
        mp[root->data] = -1;
        q.push(root);
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            if(front->left){
                q.push(front->left);
                mp[front->left->data] = front->data;
            }
            if(front->right){
                q.push(front->right);
                mp[front->right->data] = front->data;
            }
        }
        
        int count = k;
        int parent = node;
        
        while(count != 0){
            
            if(mp.find(parent) != mp.end()){
                parent = mp[parent];
            }
            count--;
        }
        return parent;
    }
};
