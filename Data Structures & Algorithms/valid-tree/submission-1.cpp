class Solution {
public:
    bool visited[107];
    vector<int> graph[107];
    void dfs(int x) {
        if(visited[x]) return;
        visited[x] = true;
        for(auto b : graph[x]) dfs(b);
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // initalize stuff
        for(int i=0; i<n; i++) {
            visited[i] = false; graph[i].clear();
        }


        if(edges.size() != n-1) return false;
        for(int i=0; i<n-1; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        // now, all need to connect
        dfs(0);
        for(int i=0; i<n; i++) {
            if(!visited[i]) return false;
        }
        return true;
    }
};
