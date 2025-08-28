class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        
        int i = 0;
        int j = 0;
        
        int zeroCount = 0;
        int ans = 0;
        int n = arr.size();
        
        while(j < n){
            if(arr[j] == 0){
                zeroCount++;
            }
            
            while(zeroCount > k){
                if(arr[i] == 0){
                    zeroCount--;
                }
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        

        return ans;
    }
};
