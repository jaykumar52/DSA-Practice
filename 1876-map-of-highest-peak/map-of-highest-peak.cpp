class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> height(m, vector<int> (n, -1));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (isWater[i][j]==1) {
                    height[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int h=1;
        while (!q.empty()){
            int size=q.size();
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                int dx[4]={-1,1,0,0};
                int dy[4]={0,0,1,-1};
                for (int i=0; i<4; i++){
                    if (x+dx[i]>=0 && x+dx[i]<m && y+dy[i]>=0 && y+dy[i]<n && height[x+dx[i]][y+dy[i]]==-1) {
                        height[x+dx[i]][y+dy[i]]=h;
                        q.push({x+dx[i], y+dy[i]});
                    }
                }
                q.pop();
            }
            h++;
        }
        return height;
    }
};