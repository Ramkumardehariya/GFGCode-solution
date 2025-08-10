class Solution {
  public:
    int countPS(string &s) {
        // code here
        int count = 0;
        int n = s.size();
        for(int center = 0;center<n;center++){
        int l = center,r = center + 1;
        //Even length palindrome substrings
        while(l>=0 && r<n && s[l] == s[r]){
            count++;
            l--;
            r++;
    }
        //Odd length palindrome substrings
        l = center-1,r = center+1;
        while(l>=0 && r<n && s[l]==s[r]){
            count++;
            l--;
            r++;
        }
        }
        return count;
    }
};