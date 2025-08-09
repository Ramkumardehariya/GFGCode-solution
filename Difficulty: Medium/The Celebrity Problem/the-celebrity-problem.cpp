class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int> st;
        
        int n = mat.size();
        
        for(int i = 0; i<n; i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if(mat[a][b] == 1){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        
        int num = st.top();
        st.pop();
        bool rowCheck = true;
        
        for(int i = 0; i<n; i++){
            if(i != num && mat[num][i] == 1){
                rowCheck = false;
            }
        }
        
        bool colCheck = true;
        
        for(int i = 0; i<n;i++){
            if(i != num && mat[i][num] == 0){
                colCheck = false;
            }
        }
        
        if(rowCheck && colCheck){
            return num;
        }
        
        return -1;
    }
};