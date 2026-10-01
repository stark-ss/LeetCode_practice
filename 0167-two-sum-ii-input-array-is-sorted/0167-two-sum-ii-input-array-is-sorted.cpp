class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int> res;
        int l=0,r=n-1;
        while(l<=r){
            if(numbers[l]+numbers[r]==target)
            break;
            else if(numbers[l]+numbers[r]<target)
            l++;
            else
            r--; 
            
        }
        res={l+1,r+1};
         return res;
    }
};