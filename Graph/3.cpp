class Solution {
  public:
        vector<int> result;
  void helper(int node, vector<vector<int>>& adj, vector<bool>&visited){
      visited[node] = true;
      
      result.push_back(node);
      
      for(auto i : adj[node]){
          if(!visited[i]){
              helper(i,adj,visited);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<bool>visited(V,false);
        
        helper(0,adj,visited);
        
        return result;
        
    }
};