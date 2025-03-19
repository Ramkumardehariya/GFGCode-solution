//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        for (int t = 0; t < tc; t++) {
            String[] input = br.readLine().split(" ");
            int arr[] = new int[input.length];

            for (int i = 0; i < arr.length; i++) arr[i] = Integer.parseInt(input[i]);

            // Read the integer k
            int k = Integer.parseInt(br.readLine());

            // Call the solution function
            Solution obj = new Solution();
            System.out.println(obj.maxProfit(arr, k));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    static int maxProfit(int price[], int k) {
        int n = price.length;
        // code here
        int prev[][] = new int[k+1][2];
        prev[0][0] = prev[0][1] = 0;

        for(int ind = n-1; ind>=0; ind--){
            int curr[][] = new int[k+1][2];
            for(int cap = 1; cap<=k; cap++){
                for(int buy = 0; buy<=1; buy++){
                    int profit = 0;
                    if(buy == 1){
                        profit = Math.max(-price[ind]+prev[cap][0],
                        prev[cap][1]);
                    }
                    else {
                        profit = Math.max(price[ind]+prev[cap-1][1],
                        prev[cap][0]);
                    }
                    curr[cap][buy] = profit;
                }
            }
            prev = curr.clone();
        }
        return prev[k][1];
    }
}

