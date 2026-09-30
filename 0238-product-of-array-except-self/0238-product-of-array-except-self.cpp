class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> t1(nums.size(),0),t2(nums.size(),0);
        int p=1,pp=1;
        for(int i=0;i<nums.size();i++){
           t1[i]=p;
           p*=nums[i];
           t2[nums.size()-1-i]=pp;
           pp*=nums[nums.size()-1-i];
        }
        for(int i=0;i<nums.size();i++){
            t1[i]=t1[i]*t2[i];
        }
        return t1;

    }
};