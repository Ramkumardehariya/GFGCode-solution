/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void solve(Node* root,unordered_map<int, int> &mp, int k, int &count, int currSum){
        if(root == NULL){
            return;
        }
        currSum += root->data;
        
        if(mp.find(currSum-k) != mp.end()){
            count += mp[currSum-k];
        }
        mp[currSum]++;
        solve(root->left, mp, k, count, currSum);
        solve(root->right, mp, k, count, currSum);
        
        mp[currSum]--;
    }
    int countAllPaths(Node *root, int k) {
        vector<int> temp;
        int count = 0;
        unordered_map<int,int> mp;
        mp[0] =1;
        solve(root, mp, k, count, 0);
        
        return count;
    }
};