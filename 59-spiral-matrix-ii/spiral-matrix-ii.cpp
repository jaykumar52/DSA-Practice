class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int sRow=0;
        int sCol=0;
        int eRow=n-1;
        int eCol=n-1;
        int num=1;

        while (num<=n*n){
            if (num<=n*n){
                for (int i=sCol; i<=eCol; i++){
                ans[sRow][i]=num++;
                }
                sRow++;
            }
            
            if (num<=n*n){
                for (int j=sRow; j<=eRow; j++){
                ans[j][eCol]=num++;          
                }
                eCol--;
            }
            
            if (num<=n*n){
                for (int k=eCol; k>=sCol; k--){
                ans[eRow][k]=num++;
                }
                eRow--;
            }
             
            if (num<=n*n){
                for (int l=eRow; l>=sRow; l--){
                ans[l][sCol]=num++;
                }
                sCol++;
            }
             
        }
        return ans;
    }
};