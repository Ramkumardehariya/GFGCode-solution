class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if(k > q.size()){
            return q;
        }
        stack<int> st;
        queue<int> ans;
        
        for(int i = 0; i<k; i++){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            ans.push(st.top());
            st.pop();
        }
        
        while(!q.empty()){
            ans.push(q.front());
            q.pop();
        }
        
        return ans;
    }
};