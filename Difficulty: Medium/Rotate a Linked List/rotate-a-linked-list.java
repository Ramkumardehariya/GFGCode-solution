//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}


// } Driver Code Ends
/* node of linked list:

class Node{
    int data;
    Node next;
    Node(int d){
        data=d;
        next=null;
    }
}

*/

class Solution {
    public Node rotate(Node head, int k) {
         Node slow = head;
        Node temp =head;
        Node fast = head.next;
        int count=1;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            temp=temp.next.next;
            fast = fast.next.next;
            count++;
        }
        if(fast==null){
            count = (count*2)-1;
        }
        else{
            count = count*2;
            temp = fast;
        }
        int rotations = k%count;
        if(rotations==0 || count==1){
            return head;
        }
        int i=1;
        Node curnext = head.next;
        Node curr = head;
        while(i<rotations){
            curr=curr.next;
            curnext = curnext.next;
            i++;
        }
        temp.next = head;
        curr.next =null;
        return curnext;
    
    }
}


//{ Driver Code Starts.

public class GFG {
    static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = br.readLine().trim();
            if (!input.isEmpty()) {
                String[] numbers = input.split("\\s+");
                for (String num : numbers) {
                    if (!num.isEmpty()) {
                        arr.add(Integer.parseInt(num));
                    }
                }
            }

            Node head = null;
            if (!arr.isEmpty()) {
                head = new Node(arr.get(0));
                Node tail = head;
                for (int i = 1; i < arr.size(); ++i) {
                    tail.next = new Node(arr.get(i));
                    tail = tail.next;
                }
            }
            int k = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            head = ob.rotate(head, k);
            printList(head);

            System.out.println("~");
        }
    }
}

// } Driver Code Ends