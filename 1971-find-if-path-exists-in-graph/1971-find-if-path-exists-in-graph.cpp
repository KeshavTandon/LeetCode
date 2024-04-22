class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<bool>& vis, int destination) {
        if (node == destination) return true;
        if (vis[node]) return false;

        vis[node] = true;

        for (int& c : graph[node]) {
            if (dfs(graph, c, vis, destination)) return true;
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n, 0);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return dfs(graph, source, vis, destination);
    }
};