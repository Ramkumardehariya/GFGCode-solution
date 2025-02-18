//{ Driver Code Starts
import java.util.*;


// } Driver Code Ends
class Solution {
    
    public int[][] kClosest(int[][] points, int k) {
        // Your code here
        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->b[0]-a[0]);
        int n=points.length;
        
        for(int i=0;i<n;i++){
            int x=Math.abs(points[i][0]);
            int y=Math.abs(points[i][1]);
            
            int sqrt=(x*x) + (y*y);
            pq.add(new int[]{sqrt,i});
            
            while(pq.size()>k){
                pq.poll();
            }
        }
        
        int[][] res=new int[k][2];
        int index=0;
        while (!pq.isEmpty()) {
            res[index++] = points[pq.poll()[1]];
        }
        return res;
    }
}

//{ Driver Code Starts.

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();

        while (t-- > 0) {
            int k = scanner.nextInt();
            int n = scanner.nextInt();
            int[][] points = new int[n][2];
            for (int i = 0; i < n; i++) {
                points[i][0] = scanner.nextInt();
                points[i][1] = scanner.nextInt();
            }
            Solution solution = new Solution();
            int[][] ans = solution.kClosest(points, k);

            Arrays.sort(ans, (a, b) -> {
                if (a[0] != b[0]) {
                    return Integer.compare(a[0], b[0]);
                }
                return Integer.compare(a[1], b[1]);
            });
            for (int[] point : ans) {
                System.out.println(point[0] + " " + point[1]);
            }
            System.out.println("~");
        }

        scanner.close();
    }
}
// } Driver Code Ends