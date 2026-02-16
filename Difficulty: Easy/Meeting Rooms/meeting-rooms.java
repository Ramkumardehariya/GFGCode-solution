class Solution {
    static boolean canAttend(int[][] arr) {
        // code here
        Arrays.sort(arr,(a,b)->a[0]-b[0]);
        int n=arr.length;
        
        for(int i=0;i<n-1;i++)
        {
            int nextStart=arr[i+1][0];
            int currEnd=arr[i][1];
            if(currEnd>nextStart)
            {
                return false;
            }
        }
        
        return true;
    }
}