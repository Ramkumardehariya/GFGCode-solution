

class Solution {
  public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string& s) {
        // Your code here
        
        int arr[26] = {0};
        
        
        for(auto ch : s){
            arr[ch-'a']++;
        }
        
        int count = 0;
        char ans;
        
        for(int i = 0; i<26; i++){
            if(arr[i] > count){
                count = arr[i];
                ans = 'a'+i;
            }
        }
        
        return ans;
    }
};