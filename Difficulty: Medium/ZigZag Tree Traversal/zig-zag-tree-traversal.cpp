/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        queue<Node*> q;
        vector<int> ans;
        
        bool flag = true;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;

            for(int i = 0; i<size; i++){
                auto node = q.front();
                q.pop();
                temp.push_back(node->data);
                
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            
            if(flag){
                for(auto it: temp){
                    ans.push_back(it);
                }
            }
            else{
                reverse(temp.begin(), temp.end());
                for(auto it: temp){
                    ans.push_back(it);
                }
            }
            flag = !flag;
        }
        return ans;
    }
};