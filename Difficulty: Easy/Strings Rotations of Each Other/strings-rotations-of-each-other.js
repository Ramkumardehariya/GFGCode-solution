/**
 * @param {string} s1
 * @param {string} s2
 * @returns {boolean}
 */

class Solution {
    areRotations(s1, s2) {
        // code here
        let temp = s1+s1;
        
        if(temp.includes(s2)){
            return true;
        }
        
        return false;
    }
}