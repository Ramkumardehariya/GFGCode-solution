class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        
        int ans = 0;
        
        if(arr[0] < arr[n-1]){
            return 0;
        }
        
        for(int i = 0; i<n-1; i++){
            ans++;
            if(arr[i] > arr[i+1]){
                break;
            }
        }
        
        return ans;
    }
};
