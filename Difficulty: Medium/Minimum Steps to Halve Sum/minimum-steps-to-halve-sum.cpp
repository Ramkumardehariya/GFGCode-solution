class Solution {
  public:
    int minOperations(vector<int>& arr) {
        priority_queue<double> pq(arr.begin(), arr.end());
        
        
        double sum = accumulate(arr.begin(), arr.end(), 0.0);
        double target = sum/2.0;
        int ans = 0;
        
        while(sum > target && !pq.empty()){
            double front = pq.top();
            ans++;
            pq.pop();

            sum -= front/2;
            
            if(front/2 != 0){
              pq.push(front/2);
            }
        }
        return ans;
    }
};