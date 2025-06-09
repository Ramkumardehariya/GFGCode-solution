/*
class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
}*/

class Solution {
    public boolean ans(Node root, int min, int max){
        if(root == null){
            return false;
        }
        
        if(min+1 == root.data && max-1 == root.data){
            return true;
        }
        
        return ans(root.left, min, root.data) || ans(root.right, root.data, max);
    }
    public boolean isDeadEnd(Node root) {
        // Code here.
        return ans(root, 0, Integer.MAX_VALUE);
    }

}