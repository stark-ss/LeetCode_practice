class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int m=0,low=1;
        for(auto& i:piles)
        m=max(m,i);
        
        while(low<m){
            int mid=low+(m-low)/2;
            long tot=0;
            for(auto& i:piles)
            tot+=(i+mid-1)/mid;
            if(tot>h)
            low=mid+1;
            else
            m=mid;
        }
        return m;
    }
};