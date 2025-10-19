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
    void solve(Node* root, int &target, int &k, priority_queue<pair<int,int>> &pq){
        if(root == NULL){
            return;
        }
        solve(root->left, target, k, pq);
        if(pq.size() < k){
            pq.push({abs(target-root->data), root->data});
        }
        else{
            if(pq.top().first > abs(target-root->data)){
                pq.pop();
                pq.push({target-root->data, root->data});
            }
        }
        
        solve(root->right, target, k, pq);
        
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        priority_queue<pair<int,int>> pq;
        
        solve(root, target, k, pq);
        vector<int> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};