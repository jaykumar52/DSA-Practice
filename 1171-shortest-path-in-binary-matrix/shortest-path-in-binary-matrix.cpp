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
        while (!q.empty()){
            int size=q.size();
            while (size--){
                x=q.front().first;
                y=q.front().second;
                if (x==n-1 && y==n-1) return dist;

                if (y<n-1 && grid[x][y+1]==0 && !visited[x][y+1]){
                    q.push({x,y+1});
                    visited[x][y+1]=true;
                } 
                if (y<n-1 && x>0 && grid[x-1][y+1]==0 && !visited[x-1][y+1]){
                    q.push({x-1, y+1});
                    visited[x-1][y+1]=true;
                }
                if (y<n-1 && x<n-1 && grid[x+1][y+1]==0 && !visited[x+1][y+1]){
                    q.push({x+1, y+1});
                    visited[x+1][y+1]=true;
                }
                if (x>0 && grid[x-1][y]==0 && !visited[x-1][y]){
                    q.push({x-1, y});
                    visited[x-1][y]=true;
                }
                if (x<n-1 && grid[x+1][y]==0 && !visited[x+1][y]){
                    q.push({x+1, y});
                    visited[x+1][y]=true;
                }
                if (y>0 && x>0 && grid[x-1][y-1]==0 && !visited[x-1][y-1]){
                    q.push({x-1, y-1});
                    visited[x-1][y-1]=true;
                }
                if (y>0 && grid[x][y-1]==0 && !visited[x][y-1]){
                    q.push({x, y-1});
                    visited[x][y-1]=true;
                }
                if (y>0 && x<n-1 && grid[x+1][y-1]==0 && !visited[x+1][y-1]){
                    q.push({x+1, y-1});
                    visited[x+1][y-1]=true;
                }
                q.pop();
            }
            dist++;
        }
        return -1;
    }
};