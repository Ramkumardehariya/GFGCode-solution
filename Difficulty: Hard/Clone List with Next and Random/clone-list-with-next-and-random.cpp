/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node* clone(Node* head){
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        Node* curr = head;
        
        while(curr != NULL){
            Node* temp = new Node(curr->data);
            if(ansHead == NULL){
                ansHead = temp;
                ansTail = temp;
            }
            else{
                ansTail->next = temp;
                ansTail = temp;
            }
            curr = curr->next;
        }
        
        return ansHead;
    }
    
    
    Node* cloneLinkedList(Node* head) {
       Node* cloneHead = clone(head);
       
       Node* originalHead = head;
       
       Node* curr1 = originalHead;
       Node* curr2 = cloneHead;
       
       while(curr1 != NULL){
           Node* next1 = curr1->next;
           curr1->next = curr2;
           
           Node* next2 = curr2->next;
           curr2->next = next1;
           
           curr1 = next1;
           curr2 = next2;
       }
       
       Node* temp = originalHead;
       
       while(temp != NULL){
           if(temp->random != NULL){
               temp->next->random = temp->random->next;
           }
           temp = temp->next->next;
       }
       
       //revert second step;
       curr1 = originalHead;
       curr2 = originalHead->next;
       
       while(curr1 != NULL && curr2 != NULL){
           curr1->next = curr2->next;
           curr1 = curr1->next;
           
           if(curr1 != NULL){
               curr2->next = curr1->next;
           }
           curr2 = curr2->next;
       }
       
       return cloneHead;
    }
};