class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> ans(n, 0);
        int j = n-1;
        
        stack<int> st;
        st.push(-1);
        
        for(int i = arr.size()-1; i>=0; i--){
            int curr = arr[i];
            
            while(curr <= st.top()){
                st.pop();
            }
            ans[j] = st.top();
            j--;
            st.push(curr);
        }
        
        return ans;
    }
};