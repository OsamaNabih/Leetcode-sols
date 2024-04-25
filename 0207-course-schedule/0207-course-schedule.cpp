class Solution {
public:
    vector<vector<int>> graph;
    bool vis[2010];
    bool onPath[2010];
    bool dfs(int nodeIdx) {
        vis[nodeIdx] = true;
        onPath[nodeIdx] = true;
        for(auto neighbourIdx : graph[nodeIdx]) {
            if (onPath[neighbourIdx]) return false;
            if (vis[neighbourIdx]) continue;
            if (!dfs(neighbourIdx)) return false;
        }
        onPath[nodeIdx] = false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        for(auto vec : prerequisites) {
            int courseIdx = vec[0];
            int preqIdx = vec[1];
            graph[preqIdx].push_back(courseIdx);
        }
        for(int i = 0; i < numCourses; i++) {
            if (vis[i]) continue;
            if (!dfs(i)) return false;
        }
        return true;
    }
};