// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    int findPosition(vector<int> &in, int ele, int n){
        for(int i = 0; i<n; i++){
            if(in[i] == ele){
                return i;
            }
        }
        return -1;
    }
    Node* solve(vector<int> &inorder, vector<int> &preorder, int &index, int inorderStart, int inorderEnd, int n){
        if(index >= n || inorderEnd < inorderStart){
            return NULL;
        }
        
        int element = preorder[index++];
        Node* root = new Node(element);
        int pos = findPosition(inorder, element, n);
        
        root->left = solve(inorder, preorder,index, inorderStart, pos-1, n);
        root->right = solve(inorder, preorder, index, pos+1, inorderEnd, n);
        
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        
        int preOrderIndex = 0;
        int n = inorder.size();
        
        Node* ans = solve(inorder, preorder, preOrderIndex, 0, n-1, n);
        return ans;
    }
};