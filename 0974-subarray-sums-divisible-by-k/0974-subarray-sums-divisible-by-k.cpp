class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> path;
        vector<vector<int>> res;
        path[0]=1;
        int c=0;
        int sum=0;
        for(int i=0;i<n;i++){
          sum+=nums[i];
          int rem=(sum%k+k)%k;
          if(path.find(rem)!=path.end()){
            c+=path[rem];
            path[rem]++;
          }
          else
          path[rem]++;
        }
         return c;
    }
};