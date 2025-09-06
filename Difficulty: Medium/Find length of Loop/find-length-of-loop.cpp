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
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head;
        Node* fast = head->next;
        
        while(slow != fast && fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast == NULL || fast->next == NULL){
            return 0;
        }
        
        slow = head;
        
        while(slow != fast){
            slow =slow->next;
            fast = fast->next->next;
        }
        // cout<<slow->data;
        
        slow =slow->next;
        int count = 1;
        
        while(slow != fast){
            slow = slow->next;
            count++;
        }
        
        return count;
    }
};