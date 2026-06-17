class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre;
        for (int i=0; i<=rowIndex; i++){
            vector<int> curr(rowIndex+1, 1);
            int j=1;
            while(j<i){
                curr[j]=pre[j-1]+pre[j];
                j++;
            }
            pre=curr;
        }
        return pre;
    }
};