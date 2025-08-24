class Solution {
  public:
    bool possible(vector<int>& arr,int day, int m, int k){
        int count = 0;
        int temp = 0;
        
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] <= day){
                count++;
            }
            else{
                temp += (count/k);
                count = 0;
            }
        }
        temp += (count/k);
        
        return (temp >= m);
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        
        if(m*k > arr.size()){
            return -1;
        }
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        

        int mid = (low+high)/2;
        
        while(low <= high){
            if(possible(arr,mid, m, k)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            mid = (low+high)/2;
        }
        
        return low;
    }
};