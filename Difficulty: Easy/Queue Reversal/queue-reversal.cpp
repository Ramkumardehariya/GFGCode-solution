class Solution {
  public:
    void solve(int i, int n, queue<int> &q){
        if(i == n){
            return ;
        }
        int num = q.front();
        q.pop();
        solve(i+1, n, q);
        q.push(num);
    }
    void reverseQueue(queue<int> &q) {
        // code here
        int n = q.size();
        solve(0, n, q);
    }
};