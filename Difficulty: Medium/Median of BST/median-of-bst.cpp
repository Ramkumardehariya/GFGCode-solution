/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, vector<int>&temp){
        if(root == NULL){
            return;
        }
        temp.push_back(root->data);
        solve(root->left, temp);
        solve(root->right, temp);
    }
    int findMedian(Node* root) {
        // Code here
        vector<int> temp;
        solve(root, temp);
        sort(temp.begin(), temp.end());
        int n = temp.size();
        
        if(n%2 == 0){
            return temp[n/2-1];
        }
        
        return temp[(n+1)/2-1];
    }
};