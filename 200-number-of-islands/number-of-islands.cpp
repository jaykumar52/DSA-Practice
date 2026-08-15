class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int islands=0;

        
        
        int one=0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]=='1') {
                    islands++;
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    grid[i][j]='0';
                    while (!q.empty()){
                        auto [x,y]=q.front();
                        q.pop();
                        int dx[4]={0,0,-1,1};
                        int dy[4]={-1,1,0,0};
                        for (int i=0; i<4; i++){
                            if (x+dx[i]>=0 && x+dx[i]<m && y+dy[i]>=0 && y+dy[i]<n && grid[x+dx[i]][y+dy[i]]=='1'){
                                grid[x+dx[i]][y+dy[i]]='0';
                                q.push({x+dx[i], y+dy[i]});
                            }
                        }
                
                    }
                }
            }
        }
        return islands;
    }
};