// User function Template for javascript

/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */

class Solution {
    kthSmallest(arr, k) {
        // code here
        const minHeap = [...arr].sort((a,b) => a-b);
        
        
        return minHeap[k-1];
    }
}