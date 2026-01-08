class Solution {
  public:
    int solve(vector<int>& arr, int k){
        int n = arr.size();
        int i = 0, j = 0;
        int ans = 0,cnt = 0;
        
        while(j < n){
            
            if(arr[j]&1){
                cnt++;
            }
          
            while(cnt > k){
                
                if(arr[i]&1){
                    cnt--;
                }
                i++;
            }
            
            ans += j - i + 1;
            
            j++;
        }
        
        return ans;
    }
    
    int countSubarrays(vector<int>& arr, int k) {
        return solve(arr, k) - solve(arr,k - 1);
    }
};