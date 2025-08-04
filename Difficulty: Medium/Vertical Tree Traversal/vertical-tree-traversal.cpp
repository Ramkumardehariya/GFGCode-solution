/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
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
        map<int,map<int,vector<int>>> nodes;
        vector<vector<int>> ans;
        
        queue<pair<Node*,pair<int,int>>> q;
        
        q.push(make_pair(root,make_pair(0,0)));
        
        
        while(!q.empty()){
            pair<Node*,pair<int,int>> node = q.front();
            q.pop();
            Node* front = node.first;
            int hd = node.second.first;
            int lvl = node.second.second;
            
            nodes[hd][lvl].push_back(front->data);
            
            if(front->left){
                q.push({front->left, {hd-1, lvl+1}});
            }
            if(front->right){
                q.push({front->right, {hd+1, lvl+1}});
            }
            
        }
        
        for(auto i: nodes){
            vector<int> temp;
            for(auto j : i.second){
                for(auto k : j.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};