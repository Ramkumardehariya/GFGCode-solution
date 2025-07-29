/**
 * @param {Queue} q
 * @returns {Queue}
 */

/*
class Queue{
    constructor(){
        this.arr = [];
        this.front = 0;
    }

    push(a){
        this.arr.push(a);
    }

    pop(){
        if(this.arr.length != this.front){
            let x = this.arr[this.front];
            this.front++;
            return x;
        }
        else
            return -1;
    }

    front_ele(){
        return this.arr[this.front];
    }

    empty(){
        if(this.arr.length != this.front)
            return false;
        else
            return true;
    }
}
*/

class Solution {
    // Function to reverse the queue.
    reversedQueue(q) {
        // code here
        let qu = new Queue();
        let arr = [];
        
        while(!q.empty()){
            arr.push(q.front_ele());
            q.pop();
        }

        for(let i = arr.length-1; i>= 0; i--){
            qu.push(arr[i]);
        }
        return qu;
    }
}