// User function Template for javascript
/**
 * @param {string} str
 * @returns {string}
 */
class Solution {
    // Function to find the maximum occurring character in a string.
    getMaxOccuringChar(s) {
        // code here
        let arr = new Array(26).fill(0);
        
        arr.fill(0);
        
        for(let ch of s){
            arr[ch.charCodeAt(0)-'a'.charCodeAt(0)]++;
        }
        
        let ans;
        let count = 0;
        
        for(let i = 0; i<26; i++){
            if(arr[i] > count){
                count = arr[i];
                ans = String.fromCharCode('a'.charCodeAt(0)+i);
            }
        }
        
        return ans;
    }
}