class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0]!=0) return false;
        int n=grid.size();
        queue<pair<int, int>> q;
        q.push({0,0});
        int move=1;
        while (!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            int dx[8]={2,2,-2,-2,1,1,-1,-1};
            int dy[8]={-1,1,-1,1,-2,2,-2,2};
            for (int i=0; i<8; i++){
                if (x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<n && grid[x+dx[i]][y+dy[i]]==move){
                    q.push({x+dx[i], y+dy[i]});
                    move++;
                    break;
                }
            }
            q.pop();
        }
        return move==n*n;
    }
};