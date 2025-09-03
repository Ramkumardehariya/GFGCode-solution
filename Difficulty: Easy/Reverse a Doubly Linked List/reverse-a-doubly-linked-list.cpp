/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* curr = head;
        Node* prevNode = NULL;
        
        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prevNode;
            curr->prev = next;
            prevNode = curr;
            curr = next;
        }
        
        return prevNode;
    }
};