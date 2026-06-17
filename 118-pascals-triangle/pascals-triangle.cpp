class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> pre;
        for (int i=1; i<=numRows; i++){
            vector<int> curr(i, 1);
            int j=1;
            while (j<i-1){
                curr[j]=pre[j]+pre[j-1];
                j++;
            }
            pre=curr;
            ans.push_back(pre);

        }
        return ans;
    }
};