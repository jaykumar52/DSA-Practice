class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefixXOR(arr.size(),0);
        prefixXOR[0]=arr[0];
        for (int i=1; i<arr.size(); i++){
            prefixXOR[i]=arr[i]^prefixXOR[i-1];
        }
        vector<int> ans(queries.size());
        for (int i=0; i<queries.size(); i++){
            if (queries[i][0]==0) ans[i]=prefixXOR[queries[i][1]];
            else ans[i]=prefixXOR[queries[i][1]]^prefixXOR[queries[i][0]-1];
        }
        return ans;
    }
};