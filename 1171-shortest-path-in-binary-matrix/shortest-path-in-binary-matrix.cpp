class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dist=1;
        int n=grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int,int>> q;
        if (grid[0][0]==0) q.push({0,0});
        else return -1;
        int x;
        int y;
        visited[0][0]=true;
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while (!q.empty()){
            int size=q.size();
            while (size--){
                x=q.front().first;
                y=q.front().second;
                if (x==n-1 && y==n-1) return dist;

                for (int i=0; i<8; i++){
                    if (x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<n && grid[x+dx[i]][y+dy[i]]==0 && !visited[x+dx[i]][y+dy[i]]){
                        q.push({x+dx[i], y+dy[i]});
                        visited[x+dx[i]][y+dy[i]]=true;
                    }
                }
                q.pop();
            }
            dist++;
        }
        return -1;
    }
};