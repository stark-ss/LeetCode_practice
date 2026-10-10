class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int high=0,low=INT_MAX;
        if((long long)m*k>n) return -1;
        for(auto& i:bloomDay){
            high=max(high,i);
            low=min(low,i);
        }
        int res=high;
        while(low<high){
            long mid=low+(high-low)/2;
            int mm=0; 
            int flower=0;
            for(auto& i:bloomDay){
              if(i<=mid)
              flower++;
              else
              flower=0;
              if(flower==k){
                mm++;
                flower=0;
              }
            }
            if(mm>=m){
                high=mid;
                res=mid;}
            else low=mid+1;
        }
        return res;
    }
};