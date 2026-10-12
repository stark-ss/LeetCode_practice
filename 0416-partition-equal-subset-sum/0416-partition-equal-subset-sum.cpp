class Solution {
public:
    bool canPartition(vector<int>& nums) {
     int n=nums.size();
     int sum=0;
     for(auto& i:nums)
     sum+=i;
     if(sum%2) return false;
     int target=sum/2;
       vector<bool> list(target+1,false);
       list[0]=true;
     for(auto& num:nums){
        for(int i=target;i>=num;i--){
            list[i]=list[i] || list[i-num];
        }
     }   
     return list[target];
    }
};