class Solution {
  public:
    
    vector<vector<int>> g;
  
    vector<int> bfs(int &V, int src) {
        vector<int> dist(V, 1e9);
        queue<int> q;
        
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for(auto &x : g[curr]) {
                if(dist[x] > 1 + dist[curr]) {
                    dist[x] = 1 + dist[curr];
                    q.push(x);
                }
            }
        }
        
        return dist;
    }
    
    int diameter(int V, vector<vector<int>>& e) {
        g.resize(V);
        
        for(auto &x : e) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        
        auto t = bfs(V, 0);
        
        int z = -1, mx = -1;
        for(int i=0; i<t.size(); i++) {
            if(t[i] > mx) {
                z = i;
                mx = t[i];
            }
        }
        
        auto tt = bfs(V, z);
        
        return *max_element(tt.begin(), tt.end());
    }
};