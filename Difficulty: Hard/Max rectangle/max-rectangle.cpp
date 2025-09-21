class Solution {
  public:
    vector<int> prevSmallerElement(vector<int> &prev, int n){
        vector<int> ans(n);
        int j= 0;
        
        stack<int> st;
        st.push(-1);
        
        for(int i = 0; i<n; i++){
            int curr = prev[i];
            
            while(st.top() != -1 && prev[st.top()] >= curr){
                st.pop();
            }
            ans[j] = st.top();
            j++;
            st.push(i);
        }
        return ans;
    }
    
    vector<int> nextSmallerElement(vector<int> &prev, int n){
        vector<int> ans(n);
        int j= n-1;
        
        stack<int> st;
        st.push(-1);
        
        for(int i = n-1; i>=0; i--){
            int curr = prev[i];
            
            while(st.top() != -1 && prev[st.top()] >= curr){
                st.pop();
            }
            ans[j] = st.top();
            j--;
            st.push(i);
        }
        return ans;
    }
  
    int histoGram(vector<int> &arr, int n){
        int ans = 0;
        
        vector<int> next(n);
        next = nextSmallerElement(arr, n);
        
        vector<int> prev(n);
        prev = prevSmallerElement(arr, n);
        
        for(int i = 0; i<n; i++){
            int l = arr[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            int w = next[i]-prev[i]-1;
            ans = max(ans, l*w);
        }
        
        return ans;
    }
    int maxArea(vector<vector<int>> &mat) {
        vector<int> temp;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int j = 0; j<m; j++){
            temp.push_back(mat[0][j]);
        }
        
        int area = histoGram(temp, m);
        
        int ans = area;
        
        for(int i = 1; i<n; i++){
            vector<int> temp2;
            for(int j = 0; j<m; j++){
                if(mat[i][j] != 0){
                    temp2.push_back(mat[i][j]+temp[j]);
                }
                else{
                    temp2.push_back(0);
                }
            }
            int area = histoGram(temp2, m);
            ans = max(ans, area);
            temp = temp2;
        }
        return ans;
    }
};