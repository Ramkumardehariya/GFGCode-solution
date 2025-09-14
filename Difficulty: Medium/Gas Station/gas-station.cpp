class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int start = 0;
        int balance = 0;
        int deficit = 0;
        int n = gas.size();
        
        for(int i = 0; i<gas.size(); i++){
            balance += (gas[i]-cost[i]);
            if(balance < 0){
                deficit += balance;
                balance = 0;
                start = i+1;
            }
        }
        if(deficit+balance < 0){
            return -1;
        }
        return start;
    }
};