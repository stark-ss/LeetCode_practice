class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int hold=-prices[0];
        int sold=0;
        int rest=0;
        for(int i=1;i<n;i++){
            int nexthold=max(hold,rest-prices[i]);
            int nextsold=hold+prices[i];
            int nextrest=max(rest,sold);
            hold=nexthold;
            sold=nextsold;
            rest=nextrest;
        }
        return max(sold,rest);
    }
};