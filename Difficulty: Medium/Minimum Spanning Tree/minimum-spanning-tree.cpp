class Solution {
  public:
    int find(int i, vector<int>& parent){
        if(i == parent[i]){
            return i;
        }
        
        return parent[i] = find(parent[i], parent);
    }
    
    void unite(int x, int y, vector<int>& parent, vector<int>& rank){
        int xp = find(x, parent);
        int yp = find(y, parent);
        
        if(xp == yp) return;
        
        if(rank[xp] < rank[yp]){
            parent[xp] = yp;
        }
        else if(rank[yp] < rank[xp]){
            parent[yp] = xp;
        }
        else{
            parent[yp] = xp;
            rank[xp]++;
        }
    }
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2]; // Sort by weight
        });
        
        vector<int> parent(V),rank(V, 0);
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
        
        int sum = 0;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];

            int up = find(u, parent);
            int vp = find(v, parent);

            if (up != vp) {
                unite(up, vp, parent, rank);
                sum += wt;
            }
        }
        
        return sum;
    }
};