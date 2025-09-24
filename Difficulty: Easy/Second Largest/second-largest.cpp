class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int first = -1;
        int second = -1;
        
        for(int i = 0; i<arr.size(); i++){
            if(first < arr[i]){
                second = first;
                first = arr[i];
            }
            else if(arr[i] > second && arr[i] < first){
                second = arr[i];
            }
        }
        return second;
    }
};