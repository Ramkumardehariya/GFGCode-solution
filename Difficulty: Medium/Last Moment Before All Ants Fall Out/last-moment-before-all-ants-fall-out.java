class Solution{
    public int getLastMoment(int n, int left[], int right[]) {
        // Initialize answer to 0
        int ans = 0;
        
        // Find the ant in 'left' array furthest from index 0
        // This is simply the maximum value in left[]
        for (int pos : left) {
            if (pos > ans) {
                ans = pos;
            }
        }
        
        // Find the ant in 'right' array furthest from index n
        // This is the ant with the minimum index (closest to 0)
        // Its travel time will be (n - min_pos)
        int minRight = n;
        boolean hasRight = false;
        
        for (int pos : right) {
            if (pos < minRight) {
                minRight = pos;
            }
            hasRight = true;
        }
        
        if (hasRight) {
            ans = Math.max(ans, n - minRight);
        }
        
        return ans;
    }
}