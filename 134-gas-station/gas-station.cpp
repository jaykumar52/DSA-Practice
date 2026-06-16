class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int fuel=0;
        int totalGas=0;
        int totalCost=0;
        int startIndex=0;

        for (int i=0; i<n; i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
            fuel+=gas[i]-cost[i];

            if (fuel<0){
                startIndex=i+1;
                fuel=0;
            }
        }
        if (totalGas<totalCost) return -1;

        return startIndex;
    }
};