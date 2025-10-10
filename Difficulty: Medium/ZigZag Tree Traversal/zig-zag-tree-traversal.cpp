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
        vector<int> ans;
        bool flag = true;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            vector<int> temp;
            int size = q.size();
            
            for(int i = 0; i<size; i++){
                Node* front = q.front();
                q.pop();
                temp.push_back(front->data);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            
            if(flag){
                for(int i = 0; i<temp.size(); i++){
                    ans.push_back(temp[i]);
                }
            }
            else{
                reverse(temp.begin(), temp.end());
                for(int i = 0; i<temp.size(); i++){
                    ans.push_back(temp[i]);
                }
            }
            flag = !flag;
        }
        
        return ans;
    }
};