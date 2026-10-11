class Solution {
public:
    void powerset(vector<vector<int>>& r,vector<int>& n,vector<int> cur,int index){
       r.push_back(cur);
       for(int i=index;i<n.size();i++){
        cur.push_back(n[i]);
        powerset(r,n,cur,i+1);
        cur.pop_back();
       }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> c;
        vector<vector<int>> res;
        powerset(res,nums,c,0);
        return res;
    }
};