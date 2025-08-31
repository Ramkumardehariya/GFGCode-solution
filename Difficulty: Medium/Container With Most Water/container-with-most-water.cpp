class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int maxi = 0;
        
        int i = 0;
        int j = arr.size()-1;
        
        while(i < j){
            maxi = max(maxi, (j-i)*min(arr[i], arr[j]));
            
            if(arr[i] < arr[j]){
                i++;
            }
            else{
                j--;
            }
        }
        
        return maxi;
    }
};