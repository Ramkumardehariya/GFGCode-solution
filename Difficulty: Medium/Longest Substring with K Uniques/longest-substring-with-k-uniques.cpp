class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        map<char,int>mp;
        int ans=-1;
        int l=0,r=0;
        int n=s.size();
        while(r<n){
            mp[s[r]]++;
            while(mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            
            if(mp.size()==k) ans=max(ans,r-l+1);
            
            r++;
        }
        
        return ans;
    }
};

