class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int s=0,ss=0;
        int start=0,tank=0;
        for(int i=0;i<n;i++){
            s+=gas[i];
            ss+=cost[i];
            tank+=gas[i]-cost[i];

            if(tank<0){
                start=i+1;
                tank=0;
            }
        }
        if(s<ss) return -1;
        return start;
    }
};