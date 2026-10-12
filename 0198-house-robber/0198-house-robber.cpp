class Solution {
public:
    int rob(vector<int>& nums) {
        int p1=nums[0],p2=0;
        for(int i=1;i<nums.size();i++)
        {
          int cur=max(p1,nums[i]+p2);
          p2=p1;
          p1=cur;  
        }
        return p1;
    }
};