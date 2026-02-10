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
    
    void createMapping(Node* originalNode, Node* copyNode, unordered_map<Node*,Node*> &mp){
        Node* curr1 = originalNode;
        Node* curr2 = copyNode;
        
        while(curr1 != NULL){
            mp[curr1] = curr2;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
    
    Node* copyRandom(Node* head, Node* ansHead, unordered_map<Node*, Node*> &mp){
        Node* curr1 = head;
        Node* curr2 = ansHead;
        
        while(curr2 != NULL){
            curr2->random = mp[curr1->random];
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        return ansHead;
    }
    
    
    Node* cloneLinkedList(Node* head) {
       Node* ansHead = clone(head);
       
       unordered_map<Node*,Node*> mp;
       
       createMapping(head, ansHead, mp);
       
       Node* ans = copyRandom(head, ansHead, mp);
       
       return ans;
    }
};