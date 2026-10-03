class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,-1);
        deque<int> tem;
        for(int i=0;i<2*n;i++){
            if(!tem.empty() && nums[i%n]>nums[tem.back()]){
                while(!tem.empty() && nums[i%n]>nums[tem.back()]){
                    res[tem.back()]=nums[i%n];
                    tem.pop_back();
                }
            }
            if(i<n)
            tem.push_back(i);
        }
        return res;
    }
};