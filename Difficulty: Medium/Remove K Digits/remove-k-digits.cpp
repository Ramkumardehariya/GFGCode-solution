class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        string ans = "";
        int n = s.size();
        
        stack<char> stk;

        for (int i=0; i<n; i++) {
            if (stk.empty()) {
                stk.push(s[i]);
                continue;
            }
            
            // custom monotonic increasing stack
            while (k && !stk.empty() && s[i]<stk.top()) {
                stk.pop();
                k--;
            }
            
            stk.push(s[i]);
        }
        
        // If more deletions are possible
        while (k && !stk.empty()) {
            stk.pop();
            k--;
        }
        
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        
        // reversing because stack follows LIFO
        reverse(ans.begin(), ans.end());
        
        // handling zeroes in front of string
        int i=0;
        while (ans[i]=='0') i++;
        if (i==ans.size()) return "0";      // all are 0 or ans is empty
        ans.erase(ans.begin(), ans.begin()+i);

        return ans;
    }
};