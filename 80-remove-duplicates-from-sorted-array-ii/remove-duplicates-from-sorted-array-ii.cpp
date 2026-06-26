class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num;
        int count;
        int i=0;
        int n=nums.size();

        while(i<n){
            num=nums[i];
            count=1;
            i++;
            while(i<n && nums[i]==num){
                count++;
                if (count>2){
                    for (int j=i; j<n-1; j++){
                        swap(nums[j], nums[j+1]);
                    }
                    n--;
                    i--;
                }
                i++;
            }
        }
        return i;
    }
};