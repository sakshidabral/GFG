class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> vis(V, false);
        
        int sum = 0;
        pq.push({0,0}); // {weight, node}
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if(vis[u] == true){
                continue;
            }
            
            vis[u] = true;
            sum += wt;
            
            for(auto &[v, edgeWt] : adj[u]){
                if(vis[v] == false){
                    pq.push({edgeWt, v});
                }
            }
        }
        
        return sum;
    }
};