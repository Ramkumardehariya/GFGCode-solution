class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        int arr[26] = {0};
        
        for(int i = 0; i<s.size(); i++){
            arr[s[i]-'a']++;
        }
        char ans = 0;
        int freq = 0;
        for(int i = 0; i<26; i++){
            if(freq < arr[i]){
                freq = arr[i];
                ans = 'a'+i;
            }
        }
        
        return ans;
    }
};