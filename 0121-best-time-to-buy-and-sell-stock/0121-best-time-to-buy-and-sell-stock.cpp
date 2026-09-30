class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit=0,index=0;
       for(int i=1;i<prices.size();i++){
        if(prices[i]-prices[index]>profit)
        profit=prices[i]-prices[index];
        else if(prices[i]-prices[index]<0)
        index=i;
       }
       
       return profit;
    }
};