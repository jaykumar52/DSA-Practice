class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> st;
        int rep;
        int mis;
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (st.count(grid[i][j])) rep=grid[i][j];
                st.insert(grid[i][j]);
            }
        }
        for (int i=1; i<=grid.size()*grid.size(); i++){
            if (st.count(i)==0){
                mis=i;
                break;
            }
        }
        return {rep,mis};
    }
};