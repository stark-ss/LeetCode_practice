class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> look;
        int count=0,kk=0,l=0,tot=0;
        for(int i=0;i<n;i++){
         if(look[nums[i]]==0)
            kk++;
           look[nums[i]]++;
           if(kk>k){
            count=0;
            look[nums[l]]--;
            l++;
            kk--;
           }
           while(look[nums[l]]>1){
            count++;
            look[nums[l]]--;
            l++;
           }
           if(kk==k)
           tot+=count+1;

        }
        return tot;
    }
};