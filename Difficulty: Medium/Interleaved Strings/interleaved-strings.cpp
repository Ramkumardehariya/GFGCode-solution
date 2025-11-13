class Solution {
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        
        if (n3 != n1+n2) return false;
        
        int i=0, j=0;
        
        while (i<n1 && j<n3) {
            if (s1[i]==s3[j]) {
                i++;
            }
            j++;
        }
        
        j=0;
        int k=0;
        
        while (k<n2 && j<n3) {
            if (s2[k]==s3[j]) {
                k++;
            }
            j++;
        }
        
        if (i==n1 && k==n2) return true;
        return false;
    }
};