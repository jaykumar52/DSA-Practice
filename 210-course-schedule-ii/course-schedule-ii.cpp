class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> prereq(numCourses);
        for (const auto &temp : prerequisites){
            prereq[temp[1]].push_back(temp[0]);
            inDegree[temp[0]]++;
        }
        queue<int> q;
        for (int i=0; i<numCourses; i++){
            if (inDegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int n=q.front();
            q.pop();
            ans.push_back(n);
            for (int num : prereq[n]){
                inDegree[num]--;
                if (inDegree[num]==0) q.push(num);
            }
        }
        if (ans.size()==numCourses) return ans;
        return {};
    }
};