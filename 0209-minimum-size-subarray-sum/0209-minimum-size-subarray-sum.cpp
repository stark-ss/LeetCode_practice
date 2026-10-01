class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int c=INT_MAX,l=0,sum=0;
        
        for(int i=0;i<n;i++){
           sum+=nums[i];
          if(sum>=target){
           while(sum>=target){
             c=min(c,i-l+1);
            sum-=nums[l];
            l++;
           }
          }
        }
        if(c==INT_MAX)
        return 0;

        return c;
    }
};