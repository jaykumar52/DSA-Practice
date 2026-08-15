class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int count=0;
        for (int i=0; i<row.size(); i+=2){
            if ((row[i]&1 && row[i+1]==row[i]-1) || (!(row[i]&1) && row[i+1]==row[i]+1)) continue;
            else {
                for (int j=i+2; j<row.size(); j++){
                    if ((row[i]&1 && row[j]==row[i]-1) || (!(row[i]&1) && row[j]==row[i]+1)) {
                        swap(row[i+1], row[j]);
                        count++;
                        continue;
                    }
                }
            }
        }
        return count;
    }
};