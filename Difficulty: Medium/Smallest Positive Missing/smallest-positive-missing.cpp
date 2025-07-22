class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        set<int> st;
        
        for(auto num: arr){
            st.insert(num);
        }
        int ans = 0;
        for(int i = 1; i<=arr.size()+2; i++){
            if(st.count(i)){
                continue;
            }
            else{
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};