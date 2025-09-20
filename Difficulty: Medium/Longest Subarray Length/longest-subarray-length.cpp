class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n, n);  // next greater element array
        vector<int> pge(n, -1); // previous greater element array
        
        // populating nge array
        for(int i = 0;i<n;i++){
            while(!st.empty() and arr[i]>arr[st.top()]){
                nge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        // emptying the stack
        while(!st.empty()){
            st.pop();
        }
        
        // populating the pge array
        for(int i = n-1;i>=0;i--){
             while(!st.empty() and arr[i]>arr[st.top()]){
                pge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        // finding the max answer
        int ans = 0;
        for(int i = 0;i<n;i++){
            int len = nge[i] - pge[i] - 1;
            if(arr[i]<=len){
                ans = max(ans, len);
            }
        }
        
        return ans;
    }
};