class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n+1,0);
        int temp=1;
        for (int i=1; i<=n; i++){
            if ((i&(i-1))==0) {
                arr[i]=1;
                temp=i;
            }
            else arr[i]=arr[temp]+arr[i-temp];
        }
        return arr;
    }
};