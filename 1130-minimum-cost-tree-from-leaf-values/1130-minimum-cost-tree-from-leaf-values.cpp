class Solution {
public:
    pair<int,int> calculate(int i,int j,vector<int>& ar,vector<vector<pair<int,int>>>& dp){
        if(i==j) return {0,ar[i]};
        if(dp[i][j].first!=-1) return dp[i][j];
        int sum=INT_MAX;
        int leaf=0;
        for(int k=i;k<j;k++){
            auto left=calculate(i,k,ar,dp);
            auto right=calculate(k+1,j,ar,dp);
            leaf=max(left.second,right.second);
            int tot=left.second*right.second +left.first+right.first;
            sum=min(sum,tot);
        }
        dp[i][j]={sum,leaf};
        return dp[i][j];
        
        
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();

        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{-1,-1}));
        return calculate(0,n-1,arr,dp).first;
    }
};