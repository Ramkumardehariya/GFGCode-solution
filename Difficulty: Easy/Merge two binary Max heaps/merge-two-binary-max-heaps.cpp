// User function Template for C++

class Solution {
  public:
  
    void heapify(vector<int> &arr, int i, int n){
        int largest = i;
        
        int left = 2*i+1;
        int right =2*i+2;
        
        if(left < n && arr[left] > arr[largest]){
            largest = left;
        }
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }
        
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, largest, n);
        }
    }
    
    
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        vector<int> ans;
        
        for(int i = 0; i<a.size(); i++){
            ans.push_back(a[i]);
        }
        for(int j = 0; j<b.size(); j++){
            ans.push_back(b[j]);
        }
        
        int size = ans.size();
        
        for(int i = size/2-1; i>=0; i--){
            heapify(ans, i, size);
        }
        
        return ans;
    }
};