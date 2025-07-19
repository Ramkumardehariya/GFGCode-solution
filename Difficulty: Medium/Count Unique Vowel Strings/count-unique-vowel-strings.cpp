class Solution {
  public:
  
    int factorial(int num){
        
        int ans = 1;
        
        for(int i = 2; i<=num; i++){
            ans = ans*i;
        }
        
        return ans;
    }
    int vowelCount(string& s) {
        // code here
        int temp[5] = {0};
        
        for(int i = 0; i<s.length(); i++){
            if(s[i] == 'a'){
                temp[0]++;
            }
            else if(s[i] == 'e'){
                temp[1]++;
            }
            else if(s[i] == 'i'){
                temp[2]++;
            } 
            else if(s[i] == 'o'){
                temp[3]++;
            }
            else if(s[i] == 'u'){
                temp[4]++;
            }
        }
        
        int ways = 1;
        int count = 0;
        
        for(auto it : temp){
            if(it > 0){
                count++;
                ways *= it;
            }
        }
        
        // cout<<ways<<count;
        if(count == 0){
            return 0;
        }
        
        return ways*factorial(count);
    }
};