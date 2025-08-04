/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        map<int,int> mp;
        
        queue<pair<Node*,int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* front = temp.first;
            
            int hd = temp.second;
            
            // if(mp.find(hd) == mp.end()){
                mp[hd] = front->data;
            
            if(front->left){
                q.push({front->left, hd-1});
            }
            if(front->right){
                q.push({front->right, hd+1});
            }
            
        }
        
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};