class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n=prices.size();
        int  hold1=-prices[0];
        int  hold2=-prices[0];
        int sold1=0;
        int sold2=0;
        for(int i=1;i<n;i++){
            int nexthold1=max(hold1,0-prices[i]);
            int nextsold1=max(sold1,hold1+prices[i]);
            int nexthold2=max(hold2,sold1-prices[i]);
            int nextsold2=max(sold2,hold2+prices[i]);
            hold1=nexthold1;
            hold2=nexthold2;
            sold1=nextsold1;
            sold2=nextsold2;
        }
        return sold2;
    }
};