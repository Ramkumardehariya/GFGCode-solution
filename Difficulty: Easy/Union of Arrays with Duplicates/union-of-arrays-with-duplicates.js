/**
 * @param {number[]} a
 * @param {number[]} b
 * @returns {number[]}
 */
class Solution {
    findUnion(a, b) {
        // code here
        const st = new Set();
        
        for(let num of a){
            st.add(num);
        }
        
        for(let num of b){
            st.add(num);
        }
        
        return Array.from(st).sort((a,b) => a-b);
    }
}