class Solution {
  public:
    void solve(queue<int> &q){
        if(q.empty()){
            return;
        }
        
        int num = q.front();
        q.pop();
        
        solve(q);
        q.push(num);
    }
    void reverseQueue(queue<int> &q) {
        // code here
        solve(q);
    }
};