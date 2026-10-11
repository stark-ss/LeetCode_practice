class Solution {
public:
void powerset(vector<int>& n,vector<int>& c,vector<vector<int>>& r,int index){
    r.push_back(c);
    for(int i=index;i<n.size();i++){
        if(i>index && n[i]==n[i-1])
        continue;
        c.push_back(n[i]);
        powerset(n,c,r,i+1);
        c.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> cur;
        vector<vector<int>> res;
        powerset(nums,cur,res,0);
        return res;
    }
};