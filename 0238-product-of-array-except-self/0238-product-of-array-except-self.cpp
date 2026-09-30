class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> t1(n);
        int p=1;
        t1[n-1]=1;
        for( int i=n-2;i>=0;i--){
            t1[i]=t1[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            t1[i]=t1[i]*p;
            p*=nums[i];
        }


        return t1;

    }
};