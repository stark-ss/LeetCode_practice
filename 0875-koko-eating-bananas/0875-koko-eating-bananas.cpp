class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int top=0;
        for(auto& i: piles)
        top=max(top,i);
        int low=1;
        while(low<top){
            long mid=low+(top-low)/2;
            long time=0;
            for(auto& i:piles){
                time+=(i+mid-1)/mid;
            }
            if(time>h)
            low=mid+1;
            else top=mid;
        }
        return top;
    }
};