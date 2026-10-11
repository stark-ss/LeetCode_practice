class Solution {
public:
   void check(vector<int>& n,vector<vector<int>>& r,vector<int>& cur,int sum,int& t,int index){
    if(sum==t) {r.push_back(cur); return;}
    else if(sum>t) return;
    for(int i=index;i<n.size();i++){
        sum+=n[i];
        cur.push_back(n[i]);
        check(n,r,cur,sum,t,i);
        sum-=n[i];
        cur.pop_back();
    }

   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> c;
        vector<vector<int>> res;
        check(candidates,res,c,0,target,0);
        return res;
    }
};