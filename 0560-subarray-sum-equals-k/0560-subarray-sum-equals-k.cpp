class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> res;
        int sum=0,c=0;
        res[0]=1;
        for(int i:nums){
            sum+=i;
            int t=sum-k;
            if(res.find(t)!=res.end())
            c+=res[t];
            res[sum]++;
        }
        return c;
    }
};