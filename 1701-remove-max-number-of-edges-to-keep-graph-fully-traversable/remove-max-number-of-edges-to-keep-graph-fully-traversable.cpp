class DSU {
private:
    vector<int> parent;
    vector<int> rank;
    int components;

public:
    // Constructor initializes DSU for 'n' nodes
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        components = n;
        // Each node is its own parent initially
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    // Path compression to find the root of 'x'
    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }
    // Union by rank to merge sets containing 'x' and 'y'
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;
        // Attach smaller tree under larger tree
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
        components--;
    }

    bool isSingle() { return components == 1; }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Lambda function to sort edges based on type, prioritizing type 3
        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            return v1[0] > v2[0];
        };
        sort(begin(edges), end(edges), lambda);
        DSU Alice(n); // DSU for Alice
        DSU Bob(n);   // DSU for Bob

        int addedEdge = 0; // Counter for edges added to the graph

        for (auto& edge : edges) { // For each edge -
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            // Type 3 edges for both Alice and Bob
            if (type == 3) {
                bool add = false;
                // Try to union nodes for Alice
                if (Alice.find(u) != Alice.find(v)) {
                    Alice.Union(u, v);
                    add = true;
                }
                // Try to union nodes for Bob
                if (Bob.find(u) != Bob.find(v)) {
                    Bob.Union(u, v);
                    add = true;
                }
                if (add)
                    addedEdge++;
            } else if (type == 2) { // Type 2 edges for Bob only
                if (Bob.find(u) != Bob.find(v)) {
                    Bob.Union(u, v);
                    addedEdge++;
                }
            } else { // Type 1 edges for Alice only
                if (Alice.find(u) != Alice.find(v)) {
                    Alice.Union(u, v);
                    addedEdge++;
                }
            }
        }
        // Check if both Alice and Bob's graphs are fully connected
        if (Alice.isSingle() && Bob.isSingle()) {
            // Return maximum removable edges
            return edges.size() - addedEdge;
        }

        return -1;
    }
};