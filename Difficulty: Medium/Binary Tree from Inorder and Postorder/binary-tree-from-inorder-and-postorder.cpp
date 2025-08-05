/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    
    Node* solve(vector<int> &in, vector<int> &post, map<int,int> &nodeToIndex, int &index, int start, int end, int n ){
        if(index < 0 || start > end){
            return NULL;
        }
        
        int ele = post[index--];
        Node* root = new Node(ele);
        int pos = nodeToIndex[ele];
        
        root->right = solve(in, post, nodeToIndex, index, pos+1, end, n);
        root->left = solve(in, post, nodeToIndex, index, start, pos-1, n);
        
        return root;
    }
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        int n = inorder.size();
        map<int,int> nodeToIndex;
        
        for(int i = 0; i<n; i++){
            nodeToIndex[inorder[i]] = i;
        }
        
        int postIndex = n-1;
        
        Node* ans = solve(inorder, postorder, nodeToIndex, postIndex, 0, n-1, n);
        
        return ans;
    }
};