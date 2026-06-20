class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (int i=0; i<prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];
            adj[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        int finishedCourses=0;

        for (int i=0; i<numCourses; i++){
            if (indegree[i]==0) q.push(i);
        }

        while (!q.empty()){
            for (int course : adj[q.front()]){
                indegree[course]--;
                if (indegree[course]==0) q.push(course);
            }
            q.pop();
            finishedCourses++;
        }

        return (numCourses==finishedCourses);
    }
};