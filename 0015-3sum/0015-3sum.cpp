class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> s;
       for(int i=0;i<n-1;i++){
        if(i>0 && nums[i]==nums[i-1])
        continue;
        if(nums[i]>0)
        break;

        int t=-nums[i];
        int l=1+i,r=n-1;
        while(l<r){
            if(nums[l]+nums[r]==t){
                s.push_back({nums[i],nums[l],nums[r]});
                l++;
                r--;
                while(l<r && nums[l]==nums[l-1]) l++;
                while(l<r && nums[r]==nums[r+1]) r--;
            }
            else if(nums[l]+nums[r]>t)
            r--;
            else if(nums[l]+nums[r]<t)
            l++;
        }
       }
        return s;
        
    }
};