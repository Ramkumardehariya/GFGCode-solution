//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            String[] str = br.readLine().trim().split(" ");
            int n = str.length;
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(str[i]);
            }
            Solution sln = new Solution();
            int res = sln.minCostClimbingStairs(arr);
            System.out.println(res);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


//Back-end complete function Template for Java

class Solution {
    static int dp[] = new int[100000];
    
    
    static int solve(int[] cost, int i){
        if(i == 0){
            return cost[0];
        }
        if(i == 1){
            return cost[1];
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        return dp[i] = Math.min(solve(cost, i-1), solve(cost, i-2))+cost[i];
    }
    static int minCostClimbingStairs(int[] cost) {
        // Write your code here
        int n = cost.length;
        Arrays.fill(dp, -1);
        
        int ans = Math.min(solve(cost, n-1), solve(cost,n-2));
        return ans;
    }
};