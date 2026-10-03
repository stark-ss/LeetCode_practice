class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,-1);
        deque<int> tem;
        for(int i=0;i<n;i++){
            if(!tem.empty() && nums[i]>nums[tem.back()]){
                while(!tem.empty() && nums[i]>nums[tem.back()]){
                    res[tem.back()]=nums[i];
                    tem.pop_back();
                }
            }
            tem.push_back(i);
        }
        while(tem.size()>1){
           for(int i=0;i<=tem.back();i++){
            if(nums[i]>nums[tem.back()]){
            res[tem.back()]=nums[i];
            break;
            }
           }
           tem.pop_back();
        }
        return res;
    }
};