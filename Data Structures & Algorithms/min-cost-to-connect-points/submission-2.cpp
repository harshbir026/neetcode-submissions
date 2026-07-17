#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // Track the minimum distance to reach each unvisited point
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);
        
        int mstCost = 0;
        int connected = 0; // Keep track of how many nodes we've added
        
        // Start from node 0 (it costs 0 to reach the starting point)
        minDist[0] = 0; 
        
        while (connected < n) {
            int u = -1;
            int currMin = INT_MAX;
            
            // 1. Find the unvisited node with the absolute smallest distance
            for (int i = 0; i < n; i++) {
                if (!visited[i] && minDist[i] < currMin) {
                    currMin = minDist[i];
                    u = i;
                }
            }
            
            // 2. Add this node to our MST territory
            visited[u] = true;
            mstCost += currMin;
            connected++;
            
            // 3. From our newly added node, update the distances to all remaining unvisited nodes
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    
                    // If this new road is cheaper than the old road to 'v', update it!
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                    }
                }
            }
        }
        
        return mstCost;
    }
};