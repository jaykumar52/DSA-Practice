class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<int>> blue;
        unordered_map<int, vector<int>> red;

        for (int i=0; i<blueEdges.size(); i++){
            blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        for (int i=0; i<redEdges.size(); i++){
            red[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        vector<int> ans(n,-1);
        ans[0]=0;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        q.push({0, 0});
        q.push({0, 1});

        int d=0;
        while (!q.empty()){
            int size=q.size();
            d++;
            while(size--){
                auto [node, color]=q.front();
                q.pop();
                if (color==1){
                    for (int num : red[node]){
                        if (!visited[num][0]){
                            visited[num][0]=true;
                            q.push({num,0});
                            if (ans[num]==-1) ans[num]=d;
                        }
                    }
                }
                else {
                    for (int num : blue[node]){
                        if (!visited[num][1]){
                            visited[num][1]=true;
                            q.push({num,1});
                            if (ans[num]==-1) ans[num]=d;
                        }
                    }
                }
            }
        }
        return ans;
    }
};