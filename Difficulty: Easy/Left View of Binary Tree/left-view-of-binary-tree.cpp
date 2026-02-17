/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        
        queue<pair<Node*, int>> q;
        map<int,int> mp;
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            if(mp.find(it.second) == mp.end()){
                mp[it.second] = it.first->data;
            }
            
            if(it.first->left){
                q.push({it.first->left, it.second+1});
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