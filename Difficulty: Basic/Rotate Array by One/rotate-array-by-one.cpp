// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        
        int num = arr[arr.size()-1];
        arr.pop_back();
        
        arr.insert(arr.begin(), num);
    }
};