class Solution {
   public:
    bool dfs(int child, int parent, vector<int>& visited, vector<vector<int>>& adj) {
        visited[child] = 1;

        for (auto adjNode : adj[child]) {
            if (!visited[adjNode]) {
                if (dfs(adjNode, child, visited, adj)) return true;
            } else if (adjNode != parent) {
                return true;
            }
        }

        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, 0);

        if (dfs(0, -1, visited, adj)) return false;
        for (int i = 0; i < n; i++) { // Tree should be fully connected
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }
};
