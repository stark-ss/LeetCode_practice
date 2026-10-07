class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        int m=0;
        for(auto& i: trips)
          m=max(m,i[2]);

        vector<int> seat(m+1,0);
        for(auto& i:trips){
            seat[i[1]]+=i[0];
            seat[i[2]]-=i[0];
        }  
        int sum=0;
        for(auto& i:seat){
            sum+=i;
            if(sum>capacity)
            return false;
        }
        return true;
    }

};