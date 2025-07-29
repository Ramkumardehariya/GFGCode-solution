class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        vector<vector<vector<int>>> grid(26,vector<vector<int>>(2,vector<int>(2,-1)));
        // space O(26*2*2)
        // using a 3D array: 26 letters
        // For each: 2 entries → [first, last] 
        // Each entry: [index, prefix_sum]
        
        int sum=0;
        for(int i=0;i<s.size();i++){
            int ch=s[i]-'a';
            sum+=ch;
            if(grid[ch][0][0]==-1){
                grid[ch][0][0]=i;   // first occurance index
                grid[ch][0][1]=sum;  // prefix sum
            }
            else{
                grid[ch][1][0]=i;   // last occurance index
                grid[ch][1][1]=sum;  // prefix sum
            }
        }
        vector<int>ans;
        for(int i=0;i<26;i++){
            if(grid[i][1][0]==-1)continue;
            int start = grid[i][0][0],end=grid[i][1][0];
            if(end-start==1) continue;  // adjasent occurance
            
            int startSum = grid[i][0][1],endSum = grid[i][1][1];  
            
            int sum2 = endSum-startSum-i;
            int count = end-start-1;
            
            ans.push_back(97*count + sum2);
        }
        return ans;
    }
};