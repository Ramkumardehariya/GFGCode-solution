class Solution {
    int[] dr = {0,-1,1,0,0};
    int[] dc = {0,0,0,-1,1};
    
    int helper(int[][] keys,int row,int col,int n,HashMap<String,Integer> memo) {
         if(row < 0 || row >= 4 || col < 0 || col >= 3 || keys[row][col] == -1)
            return 0;
        if(n == 1) return 1;
            
        String key = row + "-" + col + "-" + n;
        if(memo.containsKey(key)) return memo.get(key);
        
        int sum = 0;
         
        for(int i = 0; i < 5; ++i) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            
            sum += helper(keys,nr,nc,n - 1,memo);
        }
        
        memo.put(key,sum);
        return sum;
    }
    
    public int getCount(int n) {
        HashMap<String,Integer> memo = new HashMap<>();
        int[][] keys = new int[][] {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        int ans = 0;
        
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 3; ++j) 
                ans += helper(keys,i,j,n,memo);
        
        return ans;
    }
}