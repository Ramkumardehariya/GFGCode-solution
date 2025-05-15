//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        int count[26];
        for(int i = 0;i<26;i++)
        {
            count[i]=0;
        }
        int sum = 0;
        for(int i = 0;i<s.size();i++)
        {
            count[s[i]-'a']++;
            sum+=count[s[i]-'a'];
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends