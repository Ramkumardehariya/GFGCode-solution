class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string> ans;
        
        for(int i = 1; i<=n; i++){
            int pow = 1;
            string temp = "";
            int num = i;
            
            while(num > 0){
                int rem = num%2;
                temp += (rem+'0');
                num = num/2;
            }

            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        
        return ans;
    }
};