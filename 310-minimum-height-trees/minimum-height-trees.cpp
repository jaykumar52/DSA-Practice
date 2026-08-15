class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1) return {0};
        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);
        vector<int> ans;
        for (const auto &it : edges){
            degree[it[0]]++;
            degree[it[1]]++;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        for (int i=0; i<n; i++){
            if (degree[i]==1) {
                q.push(i);
            }
        }
        int remainingNode=n;
        while(remainingNode>2){
            int leafCount=q.size();
            remainingNode-=leafCount;
            while(leafCount--){
                int leaf=q.front();
                q.pop();
                for (const auto &it : adj[leaf]){
                    degree[it]--;
                    if (degree[it]==1){
                        q.push(it);
                    }
                }
            }
        }
        while (!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};