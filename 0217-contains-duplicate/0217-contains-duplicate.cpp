class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> res;
        for(int i=0;i<n;i++){
            res[nums[i]]++;
        }
        for(auto& i:res){
            if(i.second>1)
            return true;
        }
        return false;
    }
};