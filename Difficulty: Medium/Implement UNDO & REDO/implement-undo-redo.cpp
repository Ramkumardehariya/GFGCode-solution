class Solution {
  public:
    
    string ans = "";
    stack<int> st;
  
    void append(char x) {
        
        ans.push_back(x);
    }

    void undo() {
        
        st.push(ans.back());
        ans.pop_back();
    }

    void redo() {
        
        if(!st.empty()){
            
            ans.push_back(st.top());
            st.pop();
        }
        
        
    }

    string read() {
        
        return ans;
    }
};