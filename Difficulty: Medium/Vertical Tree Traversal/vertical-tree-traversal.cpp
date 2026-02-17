/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        map<int,vector<int>> mp;
        vector<vector<int>> ans;
        queue<pair<Node*,int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            mp[it.second].push_back(it.first->data);
            
            if(it.first->left){
                q.push({it.first->left, it.second-1});
            }
            if(it.first->right){
                q.push({it.first->right, it.second+1});
            }
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};