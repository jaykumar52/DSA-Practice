class Solution {
private:
    int countSmall(int mid, vector<vector<int>> &matrix, int &n){
        int count=0;
        int row=0;
        int col=n-1;
        while(row<n && col>=0){
            if (matrix[row][col]<=mid){
                count+=col+1;
                row++;
            }
            else col--;
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int start=matrix[0][0];
        int end=matrix[n-1][n-1];
        int ans;
        while (start<=end){
            int mid=start+(end-start)/2;
            if (countSmall(mid, matrix, n)>=k){
                end=mid-1;
                ans=mid;
            }
            else start=mid+1;
        }
        return ans;
    }
};