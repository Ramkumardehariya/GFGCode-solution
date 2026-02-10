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
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    Node* midPoint(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            slow = slow->next;
        }
        
        return slow;
    }
    
    bool isPalindrome(Node *head) {
        Node* curr1 = head;
        Node* mid = midPoint(head);
       
        
        Node* curr2 = reverse(mid);
        
        while(curr2 != NULL){
            if(curr1->data != curr2->data){
                return false;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        return true;
    }
};