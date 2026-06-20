class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> pre(obstacleGrid[0].size(),0);
        for (int i=0; i<obstacleGrid[0].size(); i++){
            if (obstacleGrid[0][i]==0) pre[i]=1;
            else break;
        }
        vector<int> col1(obstacleGrid.size(),0);
        for (int i=0; i<obstacleGrid.size(); i++){
            if (obstacleGrid[i][0]==0) col1[i]=1;
            else break;
        }
        for (int i=1; i<obstacleGrid.size(); i++){
            vector<int> curr(obstacleGrid[0].size(),0);
            curr[0]=col1[i];
            for (int j=1; j<obstacleGrid[0].size(); j++){
                if (obstacleGrid[i][j]==0) curr[j]=curr[j-1]+pre[j];
            }
            pre=curr;
        }

        return pre[obstacleGrid[0].size()-1];
    }
};