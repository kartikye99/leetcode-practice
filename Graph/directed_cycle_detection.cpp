class Solution {
  public:
  
  bool dfshelper(int node, vector<vector<int>> &adj,vector<bool>rec, vector<bool>&visited){
      visited[node] = true;
      rec[node] = true;
      
      for(auto i : adj[node]){
          if(!visited[i]){
              if(dfshelper(i,adj,rec,visited)){
                  return true;
              }
          }
          else if(rec[i]){
               return true;   
              }
      }
      rec[node] = false;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto i :edges){
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V,false);
        vector<bool> rec(V,false);
        
        for(int i = 0 ; i <V; i++){
            if(!visited[i]){
            if(dfshelper(i,adj,rec,visited)){
                return true;
            }
                
            }
        }
        return false;
    }
};