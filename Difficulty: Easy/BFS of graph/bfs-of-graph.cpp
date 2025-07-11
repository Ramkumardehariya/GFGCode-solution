class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void bfs(vector<vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node){
        visited[node] = true;
        queue<int> q; 
        q.push(node);
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            
            for(auto neibour : adj[frontNode]){
                if(!visited[neibour]){
                    visited[neibour] = true;
                    q.push(neibour);
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        unordered_map<int, bool> visited;
        vector<int> ans;
        
        for(int i = 0; i<adj.size(); i++){
            if(!visited[i]){
                bfs(adj, visited, ans, i);
            }
        }
        
        return ans;
    }
};