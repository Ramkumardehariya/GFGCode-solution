class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int index = 0;
        for(int i = 0; i<s1.size();i++){
            int j = index;
            bool flag = true;
            while(j < s2.size()){
                if(s1[i] == s2[j]){
                    index = j;
                    flag = false;
                    break;
                }
                j++;
            }
            if(flag){
                return false;
            }
            
        }
        return true;
    }
};