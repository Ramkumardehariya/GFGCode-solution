/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
  public:
  
    Node* insertAtTail(Node* &head, Node* &tail, int data){
        Node* temp = new Node(data);
        
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        return head;
    }
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        
        Node* head1 = head;
        Node* head2 = cloneHead;
        
        while(head1 != NULL && head2 != NULL){
            Node* next = head1->next;
            head1->next = head2;
            head1 = next;
            
            next = head2->next;
            head2->next = head1;
            head2 = next;
        }
        
        temp = head;
        
        while(temp != NULL){
            if(temp->next != NULL){
                if(temp->random != NULL){
                   temp->next->random = temp->random->next;
                }
                else{
                    temp->next->random = temp->random;
                }
            }
            temp = temp->next->next;
        }
        
        head1 = head;
        head2 = cloneHead;
        
        while(head1 != NULL && head2 != NULL){
            Node* next = head1->next;
            head1->next = head1->next->next;
            head2 = next;
            
            next = head2->next;
            if(head2->next != NULL){
                head2->next = head2->next->next;
            }
            head1 = next;
        }
        
        return cloneHead;
    }
};