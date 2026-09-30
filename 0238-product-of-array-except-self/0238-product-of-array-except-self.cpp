class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> t1(nums.size(),1);
        int p=1;
        for( int i=nums.size()-2;i>=0;i--){
            t1[i]=t1[i+1]*nums[i+1];
        }
        for(int i=0;i<nums.size();i++){
            t1[i]=t1[i]*p;
            p*=nums[i];
        }


        return t1;

    }
};