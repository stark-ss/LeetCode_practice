class NumArray {
public:
     vector<int> ar;
    NumArray(vector<int>& nums) {
        int sum=0;
        for(auto& i:nums){
            sum+=i;
            ar.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)
        return ar[right];
        return ar[right]-ar[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */