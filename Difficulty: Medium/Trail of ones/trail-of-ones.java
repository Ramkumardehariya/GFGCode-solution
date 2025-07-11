class Solution {
    public int countConsec(int n) {
        // code here
        if(n == 2){
            return 1;
        }
        int firstNum = 0;
        int secondNum = 1;
        int ans = 1;
        
        for(int i = 3; i<=n; i++){
            int thirdNum = firstNum + secondNum;
            firstNum = secondNum;
            secondNum = thirdNum;
            
            ans = ans * 2 + thirdNum;
            
        }
        
        return ans;
    }
}
