class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int rem = 0;
        
        for(int i = 0; i<s.length(); i++){
            
            rem = (rem * 10 + s[i]-'0')%13;
        }
        
        if(rem == 0){
            return true;
        }
        
        return false;
    }
};