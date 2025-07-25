/**
 * @param {number[]} arr
 * @returns {number[]}
 */

class Solution {
    // Function to reverse the array.
    reverseArray(arr) {
        // your code here
        let i = 0;
        let j = arr.length-1;
        
        
        while(i < j){
            [arr[i],arr[j]] = [arr[j], arr[i]];
            
            i++;
            j--;
        }
    }
}