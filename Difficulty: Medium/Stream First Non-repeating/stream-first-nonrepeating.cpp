class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        vector<int> count(26,0);
        queue<char> q;
        string ans="";
        for(auto i:s){
            count[i-'a']++;
            if(count[i-'a']==1)q.push(i);
            while(!q.empty()&&count[q.front()-'a']>1)q.pop();
            if(q.empty())ans+='#';
            else ans+=q.front();
        }
        return ans;
    }
};