#include <bits/stdc++.h>
using namespace std;

// Your exact, perfectly optimized DSU template!
class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    void UnionBySize(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v) return;
        
        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // Edge list format: {weight, {node1, node2}}
        vector<pair<int, pair<int, int>>> edges;
        
        // 1. Build the complete graph (every point connected to every other point)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({weight, {i, j}});
            }
        }
        
        // 2. Sort edges from shortest distance to longest
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(n);
        int mstCost = 0;
        int edgesUsed = 0; // Optimization tracker
        
        // 3. Greedily pick the shortest edges
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            // If they belong to different components, it's safe to connect them
            if (ds.findPar(u) != ds.findPar(v)) {
                mstCost += wt;
                ds.UnionBySize(u, v);
                edgesUsed++;
                
                // Early Exit Optimization: A valid tree ALWAYS has exactly n - 1 edges.
                // Once we hit this, we can stop evaluating the remaining edges!
                if (edgesUsed == n - 1) break;
            }
        }
        
        return mstCost;
    }
};