/*
class Node {
    int data;
    Node left, right;

    Node(int x) {
        data = x;
        left = right = null;
    }
} */
class Solution {
    public int findMaxFork(Node root, int k) {
        int ans = -1;
        
        Node node = root;
        
        while(node != null){
            if(node.data <= k){
                ans = node.data;
                node = node.right;
            }
            else{
                node = node.left;
            }
        }
        
        return ans;
    }
}