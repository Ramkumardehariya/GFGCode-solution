class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        int maxi = 0;
        
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        
        for(int i = 0; i<mices.size(); i++){
            maxi = max(maxi, abs(mices[i]-holes[i]));
        }
        
        return maxi;
    }
};