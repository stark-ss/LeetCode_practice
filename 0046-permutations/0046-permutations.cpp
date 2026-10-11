class Solution {
public:
void permu(vector<int>& n,vector<vector<int>>& r,vector<int>& cur,vector<bool>& v){
    if(cur.size()==n.size()){
        r.push_back(cur);
        return;
    }
    for(int i=0;i<n.size();i++){
       if(!v[i]){
        v[i]=true;
        cur.push_back(n[i]);
        permu(n,r,cur,v);
        cur.pop_back();
        v[i]=false;
       }

    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        vector<bool> visit(nums.size(),false);
        permu(nums,res,cur,visit);
        return res;
    }
};