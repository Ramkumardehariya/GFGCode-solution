// User function Template for C++
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // code here
        pair<int,int> ans;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int num: arr){
            mini = min(mini, num);
            maxi = max(maxi, num);
        }
        
        ans.first = mini;
        ans.second = maxi;
        return ans;
    }
};