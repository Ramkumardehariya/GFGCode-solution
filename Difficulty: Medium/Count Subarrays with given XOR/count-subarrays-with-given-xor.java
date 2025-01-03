//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        while (tc-- > 0) {
            String s[] = br.readLine().split(" ");
            int arr[] = new int[s.length];

            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(s[i]);
            }
            int k = Integer.parseInt(br.readLine());

            Solution obj = new Solution();
            System.out.println(obj.subarrayXor(arr, k));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public long subarrayXor(int arr[], int k) {
        // code here
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        
        map.put(0,1);
        int xr = 0;
        int ans = 0;
        
        for(int i = 0; i<arr.length; i++){
            xr = xr^arr[i];
            
            int x = xr^k;
            
            if(map.containsKey(x)){
                ans += map.get(x);
            }
            
            map.put(xr, map.getOrDefault(xr,0)+1);
        }
        
        return ans;
    }
}