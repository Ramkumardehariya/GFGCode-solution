class Solution {
  public:
    bool isOperator(char &ch){
        return (ch == '+' || ch == '*' || ch == '-' || ch == '/');
    }
    bool checkRedundancy(string &s) {
        stack<char> st;
        
        for(int i = 0; i<s.size(); i++){
            char ch = s[i];
            if(ch == '(' || isOperator(ch)){
                st.push(ch);
            }
            else if(ch == ')'){
                if(st.top() == '('){
                    return true;
                }
                while(st.top() != '('){
                    st.pop();
                }
                st.pop();
            }
        }
        
        
        return false;
    }
};
