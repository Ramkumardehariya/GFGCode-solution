//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
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

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

// User Function template for C++

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    
    int countNodes(struct Node* root){
        if(root == NULL){
            return 0;
        }
        
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
        
    }
    
    bool isCBT(struct Node* root, int i , int n){
        if(root == NULL){
            return true;
        }
        if(i >= n){
            return false;
        }
        else{
            bool left = isCBT(root->left,2*i+1,n);
            bool right = isCBT(root->right,2*i+2,n);
            
            return (left&&right);
        }
        
    }
    
    bool isMaxheap(struct Node* root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        if(root->right == NULL){
            return (root->data > root->left->data);
        }
        else{
            bool left = isMaxheap(root->left);
            bool right = isMaxheap(root->right);
            
            return (left&&right) && (root->data > root->left->data) && (root->data > root->right->data);
        }
    }
    
    bool isHeap(struct Node* tree) {
        // code here
        int i = 0;
        int totalcount = countNodes(tree);
        if(isCBT(tree,i,totalcount) && isMaxheap(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends