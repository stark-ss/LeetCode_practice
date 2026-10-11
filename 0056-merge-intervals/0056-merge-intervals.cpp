class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int up=intervals[0][1];
        int low=intervals[0][0];
        for(int i=1;i<n;i++){
           if(intervals[i][0]<=up){
            up=max(up,intervals[i][1]);
           }
           else{
            res.push_back({low,up});
            up=intervals[i][1];
            low=intervals[i][0];
           }

        }
        res.push_back({low,up});
        return res;
    }
};