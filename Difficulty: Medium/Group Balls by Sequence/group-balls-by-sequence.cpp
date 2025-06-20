class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (n % k) return false;
    
        sort(arr.begin(), arr.end());
        int runLen = 1;
    
        for (int i = 1; i < n; ++i) {
            if (arr[i] == arr[i - 1] + 1) {
                ++runLen;
            } else if (arr[i] == arr[i - 1]) {
                continue;
            } else {
                if (runLen % k) return false;
                runLen = 1;
            }
        }
        return (runLen % k) == 0;
    }
};