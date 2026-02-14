class Solution {
  public:
    string firstNonRepeating(string &s) {
        string ans = "";
        queue<char> q;
        
        vector<int> arr(26,0);
        
        for(int i = 0; i<s.size(); i++){
            arr[s[i]-'a']++;
            
            q.push(s[i]);
            
            
            while(!q.empty() && arr[q.front()-'a'] > 1){
                q.pop();
            }
            
            if(q.empty()){
                ans += '#';
            }
            else{
                ans += q.front();
            }
        }
        return ans;
    }
};