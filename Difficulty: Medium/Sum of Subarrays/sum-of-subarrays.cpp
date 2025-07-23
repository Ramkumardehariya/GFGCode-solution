class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        long long total = 0;
        int n = arr.size();
    
        for (int i = 0; i < n; i++) {
            // Each element contributes: arr[i] * (i+1) * (n-i)
            total += (long long)arr[i] * (i + 1) * (n - i);
        }
    
        return (int)total;
    }
};