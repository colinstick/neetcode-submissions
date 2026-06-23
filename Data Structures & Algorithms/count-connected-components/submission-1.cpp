class Solution {
public:
    int visited[2000];
    void dfs(int x, vector<vector<int>>& adj) {
        if(visited[x]) return;
        visited[x] = true;
        for(int v : adj[x]) {
            dfs(v, adj);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) visited[i] = false;
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i, adj);
                ans++;
            }
        }

        return ans;

    }
};
