class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        string temp = "";
        for(auto ch: s){
            if(isalnum(ch)){
                temp += tolower(ch);
            }
        }
        
        int i = 0;
        int j = temp.size()-1;
        
        while(i < j){
            if(temp[i] != temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};