class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());

       int low=1,high=position[n-1]-low;
       int ans=1;
        while(low<=high){
            long mid=low+(high-low)/2;
            int pos=position[0];
            int placed=1;
            for(int i=1;i<n;i++){
                if(position[i]-pos>=mid){
                placed++;
                pos=position[i];
                }
            }
            
            if(placed>=m){
                ans=mid;
                low=mid+1;
            } 
            else high=mid-1;
        }
        return ans;
    }
};