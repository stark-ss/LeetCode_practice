class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int c=0;
        int curr=intervals[0][1];
        for(int i=1;i<n;i++){
         if(curr>intervals[i][0]){
            c++;
            curr=min(curr,intervals[i][1]);
         }
         else{
            curr=intervals[i][1];
         }
        
        }
        return c;
    }
};