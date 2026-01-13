class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int sum = 0;
        int five = 0;
        int ten = 0;
        int twenty = 0;
        
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] == 5){
                five++;
            }
            else if(arr[i] == 10){
                ten++;
                five--;
            }
            else{
                twenty++;
                if(ten == 0){
                    five -= 3;
                }
                else{
                    ten--;
                    five--;
                }
            }
            
            if(five < 0 || ten < 0){
                return false;
            }
        }
        return true;
    }
};