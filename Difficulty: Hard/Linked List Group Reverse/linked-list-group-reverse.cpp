/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
  
    Node* solve(Node* head, int k){
        if(head == NULL){
            return head;
        }
        
        int count = k;
        Node* prev = NULL;
        Node* curr = head;
        Node* next;
        
        while(curr != NULL && count != 0){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count--;
        }
        
        Node* ans = solve(curr,k);
        head->next = ans;
        
        return prev;
    }
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* prev = NULL;
        Node* curr = head;
        
        return solve(head,k);
    }
};