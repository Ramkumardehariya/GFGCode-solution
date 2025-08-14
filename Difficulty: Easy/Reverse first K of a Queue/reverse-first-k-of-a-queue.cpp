class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        queue<int> ans;
        stack<int> st;
        if(k > q.size()){
            return q;
        }
        
        for(int i = 0; i<k; i++){
            if(!q.empty()){
                st.push(q.front());
                q.pop();
            }
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