class Solution {
public:
    void targetSum(vector<int>& n,int& t,int& c,int sum,int ind){
       if(ind==n.size()){
        if(sum==t)
        c++;
        return;
       }
    
       targetSum(n,t,c,sum+n[ind],ind+1);
       targetSum(n,t,c,sum-n[ind],ind+1);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int c=0;
        targetSum(nums,target,c,0,0);
        return c;
        
    }
};