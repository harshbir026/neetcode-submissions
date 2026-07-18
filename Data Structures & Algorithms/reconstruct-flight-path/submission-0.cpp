#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to perform Hierholzer's Post-Order DFS
    void dfs(string airport, 
             unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj, 
             vector<string>& result) {
        
        // As long as there are outgoing flights from this airport
        while (!adj[airport].empty()) {
            // 1. Grab the lexicographically smallest destination
            string nextAirport = adj[airport].top();
            
            // 2. Erase the ticket so we don't use it twice
            adj[airport].pop(); 
            
            // 3. Fly to the next airport
            dfs(nextAirport, adj, result);
        }
        
        // 4. We are stuck! This airport must be at the end of our current path.
        result.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build the adjacency list where destinations are automatically sorted (Min-Heap)
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        
        for (auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }
        
        vector<string> result;
        
        // Always start the journey from JFK
        dfs("JFK", adj, result);
        
        // Because we added destinations exactly when we got stuck, the list is backward.
        reverse(result.begin(), result.end());
        
        return result;
    }
};