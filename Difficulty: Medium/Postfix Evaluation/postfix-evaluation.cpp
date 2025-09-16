class Solution {
  public:
  
    int solve(int a,int b){
      if(a*b<0 && a%b!=0){
          return (a/b)-1;
      }
      return a/b;
     }
    int evaluatePostfix(vector<string>& arr) {
        
        stack<int> st;
        
        for(auto token: arr){
            if(token == "+" || token == "-" || token == "*" || token == "/" || token == "^"){
                int left = st.top(); st.pop();
                int right = st.top(); st.pop();
                int result = 0;
                
                if(token == "+"){
                    result = right+left;
                }
                else if(token == "-"){
                    result = right-left;
                }
                else if(token == "*"){
                    result = right*left;
                }
                else if(token == "/"){
                    result = solve(right,left);
                }
                else if(token == "^"){
                    result = (int)pow(right,left);
                }
                st.push(result);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};