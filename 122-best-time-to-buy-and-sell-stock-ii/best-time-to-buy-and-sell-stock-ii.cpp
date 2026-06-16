class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy, sell;
        bool stock=false;
        int profit=0;

        for (int i=0; i<prices.size()-1; i++){
            if (!stock){
                if (prices[i]<prices[i+1]){
                    buy = prices[i];
                    stock=true;
                }
                else continue;
            }
            else{
                if(prices[i]>prices[i+1]){
                    sell=prices[i];
                    stock=false;
                    profit+=(sell-buy);
                }
                else continue;
            }
        }
        if (stock && buy<prices[prices.size()-1]){
            profit+=(prices[prices.size()-1]-buy);
        }
        return profit;
    }
};