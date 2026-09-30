class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> s;
        vector<int> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(s.find(nums[i])!=s.end()){
                res.push_back(s[nums[i]]);
                res.push_back(i);
                break;
            }
            else{
                s[target-nums[i]]=i;
            }
        }
        return res;
    }
};