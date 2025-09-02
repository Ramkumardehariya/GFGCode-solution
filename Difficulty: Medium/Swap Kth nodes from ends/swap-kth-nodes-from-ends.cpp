/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    void findKthNode(Node* &curr, int &k, Node* &prev){
        if(curr == NULL){
            return ;
        }
        
        findKthNode(curr->next, k, prev);
        k--;
        if(k == 0){
            int temp = prev->data;
            prev->data = curr->data;
            curr->data = temp;
        }
        
    }
    Node* swapKth(Node* head, int k) {
        Node* prev = head;
        Node* curr = head;
        int count = 1;
        
        while(prev != NULL && count != k){
            prev = prev->next;
            count++;
        }
        if(prev == NULL){
            return head;
        }
        
        findKthNode(curr, k, prev);
        return head;
    }
};