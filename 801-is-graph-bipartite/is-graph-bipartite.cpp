class Solution {
private:
    bool isBipartition(vector<vector<int>> &graph, vector<int> &color, int start){
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for (int num:graph[n]){
                if (color[num]==-1) {
                    color[num]=1-color[n];
                    q.push(num);
                }
                else if (color[num]==color[n]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for (int i=0; i<graph.size(); i++){
            if (color[i]==-1){
                if (isBipartition(graph, color, i)==false) return false;
            }
        }
        return true;
    }
};