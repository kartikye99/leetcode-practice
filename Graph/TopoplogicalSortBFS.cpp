class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        // Kahn's Algorithm
        
        // compute indegree of every node
        // push all the nodes with indegree = 0 in the queue
        // remove nodes one by one from queue, and add to the answer
        // for each removed node decrease the indegree of its neighbour by 1
        // if any neighbour becomes indegree == 0 push that into queue
        // if number of visited nodes != number of given vertices, then cycle exists
        
        // create adjacency list
        vector<vector<int>> adj(V);

        for (auto i : edges) {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
        }

        // create an indegree vector
        vector<int> indegree(V, 0);

        // compute indegree of every node
        for (int i = 0; i < V; i++) {
            for (int j : adj[i]) {
                indegree[j]++;
            }
        }

        // push all vertices with indegree 0 in queue
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            result.push_back(front);

            for (auto i : adj[front]) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        if (result.size() != V) {
            return {};
        }

        return result;
    }
};