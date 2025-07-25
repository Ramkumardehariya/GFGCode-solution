class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
        vector<int> pos;
        vector<int> neg;
        
        for(auto num: arr){
            if(num >= 0){
                pos.push_back(num);
            }
            else{
                neg.push_back(num);
            }
        }
        
        arr.clear();
        
        for(auto num: pos){
            arr.push_back(num);
        }
        
        for(auto num: neg){
            arr.push_back(num);
        }
    }
};