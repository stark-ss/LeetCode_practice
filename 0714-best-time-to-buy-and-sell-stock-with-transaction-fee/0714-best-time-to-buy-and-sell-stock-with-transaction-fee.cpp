class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int hold=-prices[0];
        int sold=0;
        for(int i=1;i<n;i++){
            int nexthold=max(hold,sold-prices[i]);
            int nextsold=hold+prices[i]-fee;
            sold=max(sold,nextsold);
            hold=nexthold;

        }
        return sold;
    }
};