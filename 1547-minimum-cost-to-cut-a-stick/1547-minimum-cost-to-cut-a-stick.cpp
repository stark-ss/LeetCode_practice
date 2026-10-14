class Solution {
public:
int TotalCost(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
    if(j-i==1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int curCost=INT_MAX;
    for(int k=i+1;k<j;k++){
  
        int left=TotalCost(i,k,cuts,dp);
        int right=TotalCost(k,j,cuts,dp);
        int tot=(cuts[j]-cuts[i]) +left+right;
        curCost=min(curCost,tot);

    }
    
    return dp[i][j]=curCost;
}
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int  m=cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));

        return TotalCost(0,m-1,cuts,dp);
    }
};