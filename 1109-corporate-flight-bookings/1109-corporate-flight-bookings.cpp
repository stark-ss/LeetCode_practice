class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n,0);
        int m=bookings.size();
        for(int i=0;i<m;i++){
            int pos=bookings[i][0]-1;
            res[pos]+=bookings[i][2];
            int end=bookings[i][1];
            if(end<n)
            res[end]-=bookings[i][2];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=res[i];
            res[i]=sum;
        }
        return res;
    }
};