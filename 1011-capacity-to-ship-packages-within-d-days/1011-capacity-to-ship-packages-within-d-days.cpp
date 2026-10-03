class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=1,r=0,mm=0;
        for(auto& i : weights){
        r+=i;
        mm=max(mm,i);
        }
        while(l<r){
            int mid=l+(r-l)/2;
            int w=0,d=1;
            for(auto& i:weights){
                if(w<=mid)
                w+=i;
                if(w>mid){
                    d++;
                    w=i;
                }
            }
             if(d>days) l=mid+1;
             else r=mid;
        }
        return max(r,mm);

    }
};