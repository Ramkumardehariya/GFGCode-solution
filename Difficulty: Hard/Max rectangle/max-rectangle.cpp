class Solution {
  public:
  
    void prevSmaller(vector<int> &prev, vector<int> &arr){
        stack<int> st;
        st.push(-1);
        
        for(int i = 0; i<arr.size(); i++){
            int curr = arr[i];
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }
    }
    
    void nextSmaller(vector<int> &next, vector<int> &arr){
        stack<int> st;
        st.push(-1);
        
        for(int i = arr.size()-1; i>=0; i--){
            int curr = arr[i];
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }
    }
    
    int largestArea(vector<int> &arr){
        int n = arr.size();
        vector<int> prev(n,0);
        vector<int> next(n,0);
        
        prevSmaller(prev, arr);
        nextSmaller(next, arr);
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            int l = arr[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i]-prev[i]-1;
            
            int area = l*b;
            
            ans = max(ans, area);
        }
        return ans;
    }
    
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        int ans = 0;
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    continue;
                }
                else{
                    mat[i][j] = mat[i-1][j]+1;
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            int area = largestArea(mat[i]);
            ans = max(ans, area);
        }
        return ans;
    }
};