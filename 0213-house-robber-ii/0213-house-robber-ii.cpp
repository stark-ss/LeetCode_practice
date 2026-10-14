class Solution {
public:
    int amount(int i,int j,vector<int>& n){
        int p1=0,p2=0;
        for(int k=i;k<j;k++){
            int val=n[k]+p2;
            int leave=p1;
            int cur=max(val,leave);
            p2=p1;
            p1=cur;
        }
        return p1;
    }
    int rob(vector<int>& nums) {
       int n=nums.size();
       if (n==1) return nums[0];
       if(n==2) return max(nums[0],nums[1]);
        return max(amount(1,n,nums),amount(0,n-1,nums));
      
      
    }
};