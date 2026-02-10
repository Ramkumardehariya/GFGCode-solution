/*
class Node {
  public:
    int data;
    Node* next;
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
    
    Node* addList(Node* head1, Node* head2){
        Node* curr1 = head1;
        Node* curr2 = head2;
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(curr1 != NULL && curr2 != NULL){
            int sum = curr1->data + curr2->data + carry;
            
            int num = sum%10;
            carry = sum/10;
            
            Node* temp = new Node(num);
            
            if(ansHead == NULL){
                ansHead = temp;
                ansTail = temp;
            }
            else{
                ansTail->next = temp;
                ansTail = temp;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        while(curr1 != NULL){
            int sum = curr1->data + carry;
            
            int num = sum%10;
            carry = sum/10;
            
            Node* temp = new Node(num);
            
            if(ansHead == NULL){
                ansHead = temp;
                ansTail = temp;
            }
            else{
                ansTail->next = temp;
                ansTail = temp;
            }
            curr1 = curr1->next;
        }
        
        while(curr2 != NULL){
            int sum = curr2->data + carry;
            
            int num = sum%10;
            carry = sum/10;
            
            Node* temp = new Node(num);
            
            if(ansHead == NULL){
                ansHead = temp;
                ansTail = temp;
            }
            else{
                ansTail->next = temp;
                ansTail = temp;
            }
            curr2 = curr2->next;
        }
        
        while(carry > 0){
            int sum = carry;
            
            int num = sum%10;
            carry = sum/10;
            
            Node* temp = new Node(num);
            
            if(ansHead == NULL){
                ansHead = temp;
                ansTail = temp;
            }
            else{
                ansTail->next = temp;
                ansTail = temp;
            }
        }
        
        return ansHead;
    }
    Node* addTwoLists(Node* head1, Node* head2) {
        Node* curr1 = reverse(head1);
        Node* curr2 = reverse(head2);
        
        
        Node* temp = addList(curr1, curr2);
        Node* ans = reverse(temp);
        
        while(ans->data == 0){
            ans = ans->next;
        }
        
        return ans;
    }
};