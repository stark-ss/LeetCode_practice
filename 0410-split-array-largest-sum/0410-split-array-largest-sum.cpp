class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int high=0;
        int low=nums[0];
        int res=0;
        for(int i=0;i<n;i++){
            low=max(low,nums[i]);
          high+=nums[i];
           } 
           
        while(low<high){
            int mid=low+(high-low)/2;
            long sum=0;
            int kk=1;
            for( int i=0;i<n;i++){
              if(sum+nums[i]<=mid) 
               sum+=nums[i];
               else{
                kk++;
                sum=nums[i];
               }
            }

            if(kk>k)
            low=mid+1;
            else
                high=mid;
                
        }
   return low;
    }
};