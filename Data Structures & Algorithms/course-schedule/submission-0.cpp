class Solution {
public:
    bool visited[1000]; //visited AT ALL
    bool currVisited[1000]; //visited in THIS path
    bool cycleFound(int x, vector<vector<int>>& graph) {
        if(currVisited[x]) return true;
        if(visited[x]) return false;

        visited[x] = true;
        currVisited[x] = true;

        for(int v : graph[x]) {
            if(cycleFound(v, graph)) return true;
        }

        currVisited[x] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // if loop exists, impossible
        vector<vector<int>> graph(numCourses); // b->a
        
        for(int i=0; i<numCourses; i++) {
            visited[i] = false; currVisited[i] = false;
        }

        for(int i=0; i<prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            graph[b].push_back(a);
        }

        // loop check rn
        for(int i=0; i<numCourses; i++) {
            if(cycleFound(i, graph)) {
                return false;
            }
        }

        return true;
    }
};
