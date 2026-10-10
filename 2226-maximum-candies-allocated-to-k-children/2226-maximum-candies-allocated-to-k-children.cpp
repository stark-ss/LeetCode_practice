class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int high=0;
        for(auto& i: candies)
         high=max(high,i);
         long low=1;
         long ans=0;
         while(low<=high){
          long mid=low+(high-low)/2;
          long long sets=0;
          for(auto& i:candies)
          sets+=i/mid;
          if(sets>=k) {
            low=mid+1;
            ans=mid;
            }
          else high=mid-1;
         }
         return ans;
    }
};