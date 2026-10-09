class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=0;
        int high=0;
        for(auto& i:weights){
            low=max(low,i);
            high+=i;
        }
        while(low<high){
            int mid=low+(high-low)/2;
           int d=1,w=0;
           for(auto& i:weights){
            w+=i;
            if(w>mid){
                d++;
                w=i;
            }
           }
           if(d>days)
            low=mid+1;
            else high=mid;
        }
        return high;
    }
};