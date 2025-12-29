class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int i = 0;
        int j = 0;
        int n = a.size();
        int m = b.size();
        int count = 0;
        
        
        while(i < n && j < m){
            int curr = 0;
            if(a[i] < b[j]){
                curr = a[i];
                i++;
            }
            else{
                curr = b[j];
                j++;
            }
            
            count++;
            
            if(count == k){
                return curr;
            }
        }
        
        while(i< n){
            i++;
            count++;
            if(count == k){
                return a[i-1];
            }
        }
        
        while(j < m){
            j++;
            count++;
            if(count == k){
                return b[j-1];
            }
        }
        return 0;
    }
};