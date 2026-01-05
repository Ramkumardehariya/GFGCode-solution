class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int ans = INT_MIN;
        
        int i = 0;
        int j = 0;
        int sum = 0;
        
        while(j < arr.size()){
            if(j-i < k){
                sum += arr[j];
            }
            else{
                sum += arr[j];
                sum -= arr[i];
                i++;
            }
            j++;
            if(j-i == k){
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};