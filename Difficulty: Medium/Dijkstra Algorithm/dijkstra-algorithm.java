//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = Integer.parseInt(sc.nextLine());

        while (t-- > 0) {
            int V = Integer.parseInt(sc.nextLine());
            int E = Integer.parseInt(sc.nextLine());

            List<int[]> edgeList = new ArrayList<>();

            for (int i = 0; i < E; i++) {
                String[] parts = sc.nextLine().split(" ");
                int u = Integer.parseInt(parts[0]);
                int v = Integer.parseInt(parts[1]);
                int w = Integer.parseInt(parts[2]);
                edgeList.add(new int[] {u, v, w});
                edgeList.add(new int[] {v, u, w});
            }

            int[][] edges = new int[edgeList.size()][3];
            for (int i = 0; i < edgeList.size(); i++) {
                edges[i] = edgeList.get(i);
            }

            int src = Integer.parseInt(sc.nextLine());

            Solution obj = new Solution();
            int[] res = obj.dijkstra(V, edges, src);

            for (int val : res) {
                System.out.print(val + " ");
            }
            System.out.println();
            System.out.println("~");
        }

        sc.close();
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    class Pair implements Comparable<Pair> {
        int n;
        int path;

        public Pair(int n, int path) {
            this.n = n;
            this.path = path;
        }

        @Override
        public int compareTo(Pair p2) {
            return this.path - p2.path;
        }
    }

     public void dijkstra(ArrayList<ArrayList<iPair>> adj, int src,ArrayList<Integer>res) {
        int dist[] = new int[adj.size()]; // dist[i] -> src to i
        for (int i = 0; i < adj.size(); i++) {
            if (i != src) {
                dist[i] = Integer.MAX_VALUE; // infinity
            }
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(src, 0));

        boolean vis[] = new boolean[adj.size()];

        while (!pq.isEmpty()) {
            int curr = pq.remove().n;
            if (!vis[curr]) {
                vis[curr] = true;
                for (int j = 0; j < adj.get(curr).size(); j++) {
                    iPair e = adj.get(curr).get(j);
                    int u = curr;
                    int v = e.first;
                    int wt = e.second;

                    if (dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                        pq.add(new Pair(v, dist[v]));
                    }
                }
            }
        }
        // Print shortest distance for all source to other vertices
        for (int i = 0; i < dist.length; i++) {
            res.add(dist[i]);
        }
    }
    ArrayList<Integer> dijkstra(ArrayList<ArrayList<iPair>> adj, int src) {
        ArrayList<Integer>res = new ArrayList<>();
         dijkstra(adj,src,res);
         return res;
    }
}