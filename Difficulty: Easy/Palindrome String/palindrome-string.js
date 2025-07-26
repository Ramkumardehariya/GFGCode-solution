/**
 * @param {string} s
 * @return {boolean}
 */

class Solution {
    // Function to check if a given string is a palindrome.
    isPalindrome(s) {
        // code here
        let i = 0;
        let j = s.length-1;
        
        while(i < j){
            if(s[i] !== s[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
}