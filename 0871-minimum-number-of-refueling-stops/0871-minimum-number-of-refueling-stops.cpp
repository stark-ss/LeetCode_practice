class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        int fuel=startFuel;
        int c=0;
        int dis=0;
        int i=0;
        priority_queue<int> q;
        while(fuel<target){
            while(i<n && stations[i][0]<=fuel){
                q.push(stations[i][1]);
                i++;
            }
            if(q.empty()) return -1;
            fuel+=q.top();
            q.pop();
            c++;
        }
        return c;
    }
};