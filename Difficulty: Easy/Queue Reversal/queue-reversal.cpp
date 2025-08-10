// function Template for C++

class Solution {
  public:
  
    void solve(queue<int> &ans, queue<int> &q){
        if(q.empty()){
            return;
        }
        int num = q.front();
        q.pop();
        solve(ans, q);
        ans.push(num);
    }
    queue<int> reverseQueue(queue<int> &q) {
        // code here.
        queue<int> ans;
        
        solve(ans, q);
        
        return ans;
    }
};