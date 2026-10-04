class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return false;
        stack<int> s;
        int second=INT_MIN,third=0;
        for(int i=n-1;i>=0;i--){
           if(!s.empty() && nums[i]<second)
           return true;
           else if(!s.empty() && nums[i]>nums[s.top()]){
            while(!s.empty() && nums[i]>nums[s.top()]){
            second=nums[s.top()];
            s.pop();
            }
           }
            s.push(i);
        }
        return false;
    }
};